#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = 998244353;
const int G = 3;

int n;
vector<int>L,U,A,B,C,D,H,fac,invfac;
vector<int>cL2,cL1,cU1,cU,cE;

struct node{
    int t,j,id;
};

vector<node>e[5];
vector<int>*val[5];

int qpow(int a,int b){
    ll ans = 1;
    while(b){
        if(b&1) ans = ans*a%MOD;
        a = (ll)a*a%MOD;
        b>>=1;
    }
    return ans;
}

int md(ll x){
    x%=MOD;
    if(x<0) x+=MOD;
    return x;
}

void ntt(vector<int>&a){
    int n = a.size();
    static vector<int>rt(2,1);
    static vector<int>rev;
    if((int)rt.size()<n){
        int k = __builtin_ctz(rt.size());
        rt.resize(n);
        while((1<<k)<n){
            int z = qpow(G,(MOD-1)>>(k+1));
            for(int i=1<<(k-1);i<(1<<k);i++){
                rt[i<<1] = rt[i];
                rt[i<<1|1] = (ll)rt[i]*z%MOD;
            }
            k++;
        }
    }
    rev.resize(n);
    int lg = __builtin_ctz(n);
    for(int i=0;i<n;i++){
        rev[i] = (rev[i>>1]>>1)|((i&1)<<(lg-1));
    }
    for(int i=0;i<n;i++){
        if(i<rev[i]) swap(a[i],a[rev[i]]);
    }
    for(int k=1;k<n;k<<=1){
        for(int i=0;i<n;i+=k<<1){
            for(int j=0;j<k;j++){
                int z = (ll)rt[j+k]*a[i+j+k]%MOD;
                int x = a[i+j];
                a[i+j] = x+z;
                if(a[i+j]>=MOD) a[i+j]-=MOD;
                a[i+j+k] = x-z;
                if(a[i+j+k]<0) a[i+j+k]+=MOD;
            }
        }
    }
}

void intt(vector<int>&a){
    ntt(a);
    reverse(a.begin()+1,a.end());
    int inv = qpow(a.size(),MOD-2);
    for(int &x:a){
        x = (ll)x*inv%MOD;
    }
}

int getQ(int k,int j,int cv){
    if(j<=0) return 0;
    if(k == 1) return j%MOD;
    if(j<L[k]) return 0;
    if(j>U[k]) return md(C[k]+(ll)D[k]*j);
    return (ll)md(H[j]+cv)*invfac[j-k]%MOD;
}

void calc(int i){
    int j1 = L[i]-1;
    int j2 = L[i]-2;
    int q1 = getQ(i-1,j1,cL1[i]);
    int q2 = getQ(i-1,j2,cL2[i]);
    int u = (ll)md(j1-i+1)*q1%MOD;
    int v = (ll)md(j2-i+1)*q2%MOD;
    int d = md(u-v);
    A[i] = md(-u+(ll)(L[i]-1)*d);
    B[i] = md(-d);

    for(int j=U[i-1]+1;j<=U[i];j++){
        int q = 0;
        if(i-1 == 1) q = j%MOD;
        else q = md(C[i-1]+(ll)D[i-1]*j);
        H[j] = md((ll)fac[j-i+1]*q-cE[j]);
    }

    auto get = [&](int j,int cv){
        if(j<L[i]) return 0;
        int q = getQ(i-1,j,cv);
        return md((ll)md(j-i+1)*q+A[i]+(ll)B[i]*j);
    };

    int x = get(U[i]-1,cU1[i]);
    int y = get(U[i],cU[i]);

    D[i] = md(y-x);
    C[i] = md(y-(ll)D[i]*U[i]);
}

void add(int f,int idx,int x){
    int id = e[f][idx].id;
    (*val[f])[id] += x;
    if((*val[f])[id]>=MOD) (*val[f])[id]-=MOD;
}

void work(int l,int mid,int r){
    struct seg{
        int l,r;
    };

    seg s[5];
    vector<pair<int,int>>arr;

    for(int f=0;f<5;f++){
        int le = lower_bound(e[f].begin(),e[f].end(),mid+1,[](const node&x,int y){
            return x.t<y;
        })-e[f].begin();

        int ri = upper_bound(e[f].begin(),e[f].end(),r,[](int y,const node&x){
            return y<x.t;
        })-e[f].begin();

        s[f] = {le,ri};

        if(le<ri){
            arr.push_back({e[f][le].j,e[f][ri-1].j});
        }
    }

    if(arr.empty()) return;

    sort(arr.begin(),arr.end());

    vector<pair<int,int>>range;

    for(auto [x,y]:arr){
        if(range.empty() || x>range.back().second+1){
            range.push_back({x,y});
        }else{
            range.back().second = max(range.back().second,y);
        }
    }

    for(auto [jl,jr]:range){
        int th = min(mid,jr);
        if(th<l) continue;

        ll cnt = 0;

        for(int f=0;f<5;f++){
            for(int i=s[f].l;i<s[f].r;i++){
                int j = e[f][i].j;
                if(j>=jl && j<=jr) cnt++;
            }
        }

        int len = th-l+1;

        if((ll)len*cnt<=12000){
            for(int f=0;f<5;f++){
                for(int z=s[f].l;z<s[f].r;z++){
                    int j = e[f][z].j;
                    if(j<jl || j>jr) continue;

                    ll x = 0;
                    ll y = 0;
                    int rr = min(th,j);

                    for(int t=l;t<=rr;t++){
                        int num = fac[j-t];
                        x += (ll)A[t]*num%MOD;
                        y += (ll)B[t]*num%MOD;
                    }

                    x%=MOD;
                    y%=MOD;

                    int num = md(x+(ll)j*y);

                    add(f,z,num);
                }
            }
            continue;
        }

        int dl = max(0,jl-th);
        int dr = jr-l;

        if(dl>dr) continue;

        int len2 = dr-dl+1;
        int sz = 1;

        while(sz<len+len2-1) sz<<=1;

        vector<int>a(sz);
        vector<int>b(sz);
        vector<int>c(sz);

        for(int i=l;i<=th;i++){
            a[i-l] = A[i];
            b[i-l] = B[i];
        }

        for(int i=dl;i<=dr;i++){
            c[i-dl] = fac[i];
        }

        ntt(a);
        ntt(b);
        ntt(c);

        for(int i=0;i<sz;i++){
            a[i] = (ll)a[i]*c[i]%MOD;
            b[i] = (ll)b[i]*c[i]%MOD;
        }

        intt(a);
        intt(b);

        for(int f=0;f<5;f++){
            for(int z=s[f].l;z<s[f].r;z++){
                int j = e[f][z].j;
                if(j<jl || j>jr) continue;

                int idx = j-l-dl;

                if(idx<0 || idx>=sz) continue;

                int num = md(a[idx]+(ll)j*b[idx]);

                add(f,z,num);
            }
        }
    }
}

void cdq(int l,int r){
    if(l == r){
        calc(l);
        return;
    }

    int mid = (l+r)>>1;

    cdq(l,mid);
    work(l,mid,r);
    cdq(mid+1,r);
}

void test(){
    cin>>n;

    vector<int>l(n+1);
    vector<int>r(n+1);

    for(int i=1;i<=n;i++){
        cin>>l[i]>>r[i];
    }

    L.assign(n+1,0);
    U.assign(n+1,0);

    int mx = 0;

    for(int i=1;i<=n;i++){
        mx = max(mx,l[i]);
        L[i] = max(i,mx);
    }

    vector<int>R(n+1);

    int mn = n+1;

    for(int i=n;i>=1;i--){
        mn = min(mn,r[i]);
        R[i] = mn;
    }

    if(L[1] != 1){
        cout<<0<<"\n";
        return;
    }

    for(int i=1;i<=n;i++){
        if(L[i]>R[i]){
            cout<<0<<"\n";
            return;
        }
    }

    if(n == 1){
        cout<<1<<"\n";
        return;
    }

    U[1] = 1;

    for(int i=2;i<=n;i++){
        U[i] = R[i];
    }

    A.assign(n+1,0);
    B.assign(n+1,0);
    C.assign(n+1,0);
    D.assign(n+1,0);
    H.assign(n+1,0);

    cL2.assign(n+1,0);
    cL1.assign(n+1,0);
    cU1.assign(n+1,0);
    cU.assign(n+1,0);
    cE.assign(n+1,0);

    fac.assign(n+1,1);
    invfac.assign(n+1,1);

    for(int i=1;i<=n;i++){
        fac[i] = (ll)fac[i-1]*i%MOD;
    }

    invfac[n] = qpow(fac[n],MOD-2);

    for(int i=n;i>=1;i--){
        invfac[i-1] = (ll)invfac[i]*i%MOD;
    }

    C[1] = 0;
    D[1] = 1;

    for(int i=0;i<5;i++){
        e[i].clear();
    }

    for(int i=2;i<=n;i++){
        e[0].push_back({i,L[i]-2,i});
        e[1].push_back({i,L[i]-1,i});
        e[2].push_back({i,U[i]-1,i});
        e[3].push_back({i,U[i],i});
    }

    int idx = 2;

    for(int j=2;j<=n;j++){
        while(idx<=n && U[idx]<j){
            idx++;
        }

        e[4].push_back({idx,j,j});
    }

    val[0] = &cL2;
    val[1] = &cL1;
    val[2] = &cU1;
    val[3] = &cU;
    val[4] = &cE;

    cdq(2,n);

    int ans = md(C[n]+(ll)D[n]*n);

    cout<<ans<<"\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T = 1;
    // cin>>T;

    while(T--) test();

    return 0;
}