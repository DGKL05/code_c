#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
const int G = 3;

vector<int>invn;

ll qpow(ll a,ll b){
    ll ans = 1;
    while(b){
        if(b&1) ans = ans*a%mod;
        a = a*a%mod;
        b >>= 1;
    }
    return ans;
}

void ntt(vector<int>&a,bool inv){
    int n = a.size();

    for(int i=1,j=0;i<n;i++){
        int bit = n>>1;
        while(j&bit){
            j ^= bit;
            bit >>= 1;
        }
        j ^= bit;
        if(i<j) swap(a[i],a[j]);
    }

    for(int len=2;len<=n;len<<=1){
        int wn = qpow(G,(mod-1)/len);
        if(inv) wn = qpow(wn,mod-2);

        for(int i=0;i<n;i+=len){
            ll w = 1;

            for(int j=0;j<len/2;j++){
                int x = a[i+j];
                int y = w*a[i+j+len/2]%mod;

                a[i+j] = x+y;
                if(a[i+j]>=mod) a[i+j] -= mod;

                a[i+j+len/2] = x-y;
                if(a[i+j+len/2]<0) a[i+j+len/2] += mod;

                w = w*wn%mod;
            }
        }
    }

    if(inv){
        int x = qpow(n,mod-2);
        for(auto &v:a) v = 1LL*v*x%mod;
    }
}

vector<int> mul(vector<int>a,vector<int>b,int lim=-1){
    if(a.empty() || b.empty()) return {};

    int need = a.size()+b.size()-1;
    if(lim!=-1) need = min(need,lim);

    int n = 1;
    while(n<(int)a.size()+(int)b.size()-1) n <<= 1;

    a.resize(n);
    b.resize(n);

    ntt(a,0);
    ntt(b,0);

    for(int i=0;i<n;i++){
        a[i] = 1LL*a[i]*b[i]%mod;
    }

    ntt(a,1);

    a.resize(need);

    return a;
}

vector<int> invpoly(vector<int>a,int n){
    vector<int>b(1,qpow(a[0],mod-2));

    for(int len=2;len<2*n;len<<=1){
        int m = min(len,n);

        vector<int>c(min((int)a.size(),m));

        for(int i=0;i<(int)c.size();i++){
            c[i] = a[i];
        }

        vector<int>d = mul(c,b,m);
        d.resize(m);

        for(int i=0;i<m;i++){
            d[i] = (mod-d[i])%mod;
        }

        d[0] += 2;
        if(d[0]>=mod) d[0] -= mod;

        b = mul(b,d,m);
        b.resize(m);
    }

    b.resize(n);

    return b;
}

vector<int> lnpoly(vector<int>a,int n){
    if(n==1) return vector<int>(1,0);

    vector<int>d(max(0,(int)a.size()-1));

    for(int i=1;i<(int)a.size();i++){
        d[i-1] = 1LL*a[i]*i%mod;
    }

    vector<int>b = invpoly(a,n);
    vector<int>c = mul(d,b,n-1);

    vector<int>ans(n);

    for(int i=1;i<n;i++){
        int x = i-1<(int)c.size()?c[i-1]:0;
        ans[i] = 1LL*x*invn[i]%mod;
    }

    return ans;
}

vector<int> exppoly(vector<int>a,int n){
    vector<int>b(1,1);

    for(int len=2;len<2*n;len<<=1){
        int m = min(len,n);

        vector<int>lb = lnpoly(b,m);
        vector<int>c(m);

        for(int i=0;i<m;i++){
            int x = i<(int)a.size()?a[i]:0;

            c[i] = x-lb[i];
            if(c[i]<0) c[i] += mod;
        }

        c[0]++;
        if(c[0]>=mod) c[0] -= mod;

        b = mul(b,c,m);
        b.resize(m);
    }

    b.resize(n);

    return b;
}

vector<int> polypow(vector<int>a,ll k,int n){
    vector<int>ans(n);

    if(n==0) return {};

    if(k==0){
        ans[0] = 1;
        return ans;
    }

    int p = -1;

    for(int i=0;i<(int)a.size();i++){
        if(a[i]){
            p = i;
            break;
        }
    }

    if(p==-1 || 1LL*p*k>=n) return ans;

    int sh = p*k;
    int m = n-sh;

    int c = a[p];
    int ic = qpow(c,mod-2);

    vector<int>b(m);

    for(int i=0;i<m && p+i<(int)a.size();i++){
        b[i] = 1LL*a[p+i]*ic%mod;
    }

    vector<int>l = lnpoly(b,m);

    for(auto &x:l){
        x = 1LL*x*(k%mod)%mod;
    }

    b = exppoly(l,m);

    int ck = qpow(c,k);

    for(int i=0;i<m;i++){
        ans[i+sh] = 1LL*b[i]*ck%mod;
    }

    return ans;
}

void test(){
    int n=0,k=0;
    cin>>n>>k;

    vector<int>w(n);

    for(auto &x:w){
        cin>>x;
    }

    if(n==1){
        cout<<w[0]<<"\n";
        return;
    }

    invn.assign(n+1,0);
    invn[1] = 1;

    for(int i=2;i<=n;i++){
        invn[i] = mod-1LL*(mod/i)*invn[mod%i]%mod;
    }

    vector<int>fac(n+1),ifac(n+1);

    fac[0] = 1;

    for(int i=1;i<=n;i++){
        fac[i] = 1LL*fac[i-1]*i%mod;
    }

    ifac[n] = qpow(fac[n],mod-2);

    for(int i=n;i>=1;i--){
        ifac[i-1] = 1LL*ifac[i]*i%mod;
    }

    vector<int>f(n),g(n);

    for(int i=0;i<n;i++){
        f[i] = 1LL*w[i]*ifac[i]%mod;
    }

    for(int i=0;i+1<n;i++){
        g[i] = 1LL*w[i+1]*ifac[i]%mod;
    }

    if(k==n){
        vector<int>p = polypow(f,n-1,n-1);
        vector<int>a = mul(g,p,n-1);

        ll ans = 1LL*a[n-2]*fac[n-2]%mod;

        cout<<ans<<"\n";
        return;
    }

    int p = k-1;
    int q = n-k-1;
    int m = n-k;

    vector<int>fp = polypow(f,p,n-1);
    vector<int>a = mul(g,fp,n-1);

    a.resize(n-1);

    vector<int>fm = polypow(f,m,q+1);

    ll ans = 0;

    for(int i=0;i<=q;i++){
        int j = p+i;

        ll x = 1LL*a[j]*fac[j]%mod*ifac[i]%mod;

        ans += x*fm[q-i]%mod;

        if(ans>=mod) ans -= mod;
    }

    ans = ans*fac[q]%mod;

    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T = 1;

    while(T--) test();

    return 0;
}