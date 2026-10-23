
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void test(){
    int n,q;
    cin>>n>>q;

    vector<ll>a(n+1),pre(n+1,0),sum(n+1,0);

    for(int i=1;i<=n;i++){
        cin>>a[i];
        pre[i]=pre[i-1]+a[i];
        sum[i]=sum[i-1]+pre[i];
    }

    auto calc = [&](ll x)->ll{
        if(x==0) return 0LL;

        int l=1,r=n;
        while(l<r){
            int mid=(l+r)/2;
            if(1LL*mid*(mid+1)/2>=x) r=mid;
            else l=mid+1;
        }

        ll pos=x-1LL*l*(l-1)/2;
        return sum[l-1]+pre[pos];
    };

    while(q--){
        ll l,r;
        cin>>l>>r;
        cout<<calc(r)-calc(l-1)<<"\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T=1;
    while(T--) test();

    return 0;
}
