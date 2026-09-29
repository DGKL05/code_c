#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MOD = 998244353;
const int N = 200005;

ll fac[N],invfac[N];

ll qpow(ll a,ll b){
    ll ans = 1;
    while(b){
        if(b&1) ans = ans*a%MOD;
        a = a*a%MOD;
        b>>=1;
    }
    return ans;
}

ll C(int n,int m){
    if(n<0 || m<0 || m>n) return 0;
    return fac[n]*invfac[m]%MOD*invfac[n-m]%MOD;
}

ll F(int x,int y){
    if(x<0 || y<0) return 0;

    ll ans = C(x+y+2,x+1)-1;

    if(ans<0) ans += MOD;

    return ans;
}

ll get(int a1,int a2,int b1,int b2){
    if(a1>a2 || b1>b2) return 0;

    ll ans = 0;

    ans += F(a2,b2);
    ans -= F(a1-1,b2);
    ans -= F(a2,b1-1);
    ans += F(a1-1,b1-1);

    ans %= MOD;

    if(ans<0) ans += MOD;

    return ans;
}

void test(){
    int n;
    ll x;

    cin>>n>>x;

    vector<ll>a(n+1);

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    sort(a.begin()+1,a.end());

    map<ll,pair<int,int>>mp;

    for(int i=1;i<=n;){
        int j = i;

        while(j<=n && a[j] == a[i]){
            j++;
        }

        mp[a[i]] = {i,j-1};

        i = j;
    }

    ll ans = 0;

    /*
        奇数长度
        中间元素本身等于 x
    */
    if(mp.count(x)){
        auto [l,r] = mp[x];

        for(int p=l;p<=r;p++){
            ans += C(n-1,p-1);
            ans %= MOD;
        }
    }

    /*
        偶数长度
        两个中间值不同
    */
    for(auto [val,seg]:mp){

        if(val >= x) continue;

        ll need = 2*x-val;

        if(!mp.count(need)) continue;

        auto [l1,r1] = seg;
        auto [l2,r2] = mp[need];

        /*
            A = p-1
            B = n-q

            p in [l1,r1]
            q in [l2,r2]
        */

        int a1 = l1-1;
        int a2 = r1-1;

        int b1 = n-r2;
        int b2 = n-l2;

        ans += get(a1,a2,b1,b2);
        ans %= MOD;
    }

    /*
        偶数长度
        中间两个都是 x
    */
    if(mp.count(x)){
        auto [l,r] = mp[x];

        for(int q=l+1;q<=r;q++){

            ll now = C(n-1,q-2);

            if(l>=2){
                now -= C(n-q+l-1,l-2);
                now %= MOD;
            }

            if(now<0) now += MOD;

            ans += now;
            ans %= MOD;
        }
    }

    cout<<ans%MOD<<"\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    fac[0] = 1;

    for(int i=1;i<N;i++){
        fac[i] = fac[i-1]*i%MOD;
    }

    invfac[N-1] = qpow(fac[N-1],MOD-2);

    for(int i=N-1;i>=1;i--){
        invfac[i-1] = invfac[i]*i%MOD;
    }

    int T = 1;
    cin>>T;

    while(T--) test();

    return 0;
}