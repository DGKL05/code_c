#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void test(){
    int n,m,k;
    cin>>n>>m>>k;

    vector<ll>a(n);

    ll sum = 0;
    ll mx = 0;

    for(int i=0;i<n;i++){
        cin>>a[i];
        sum += a[i];
        mx = max(mx,a[i]);
    }

    auto check = [&](ll mid){

        if(mid < mx) return false;

        vector<int>f(n);
        vector<int>len(n);

        ll now = 0;
        int r = 0;

        for(int l=0;l<n;l++){

            while(r < l+n && now+a[r%n] <= mid){
                now += a[r%n];
                r++;
            }

            len[l] = r-l;
            f[l] = r%n;

            now -= a[l];
        }

        vector<int>vis(n,-1);
        vector<int>path;

        int x = 0;

        while(vis[x] == -1){
            vis[x] = path.size();
            path.push_back(x);
            x = f[x];
        }

        int st = vis[x];

        ll cnt = path.size()-st;
        ll move = 0;

        for(int i=st;i<path.size();i++){
            move += len[path[i]];
        }

        ll q = move/n;

        return cnt <= 1LL*k*q;
    };

    ll l = mx;
    ll r = sum;

    while(l < r){
        ll mid = (l+r)/2;

        if(check(mid)){
            r = mid;
        }else{
            l = mid+1;
        }
    }

    ll ans = sum+1LL*(m-1)*l;

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