#include<bits/stdc++.h>
using namespace std;
using ll =long long;
int n=0;
struct TARR{
    vector<ll>tarr;

    TARR(int n,vector<ll>arr){
        tarr.resize(n+1);
    }

    int lowite(int x){
        return x&(-x);
    }

    void update(int idx , ll num){
        // cout<<idx<<" "<<n<<"\n";
        while(idx<=n){
            
            tarr[idx] += num;
            idx += lowite(idx);
        }
    }

    ll get(int idx){
        ll ans = 0;
        while(idx>0){
            ans += tarr[idx];
            idx -= lowite(idx);
        }
        return ans;
    }

    ll get(int l,int r){
        return get(r) - get(l-1);
    }

};

void test()
{
    cin>>n;
    int q=0;
    cin>>q;
    vector<ll>arr(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    TARR t_arr (n , arr);

    for(int i=1;i<=n;i++){
        t_arr.update(i,arr[i]);
    }

    while(q--){
        int op = 0;
        cin>>op;
        if(op == 1){
            int idx=0;
            cin>>idx;
            ll a = arr[idx];
            ll b = arr[idx+1];
            swap(arr[idx] , arr[idx+1]);
            t_arr.update(idx , b - a);
            // cout<<"a - b : "<<a-b<<"\n";
            t_arr.update(idx+1 , a - b);
        }else{
            int l = 0;
            int r = 0;
            cin>>l>>r;

            cout<<1LL*t_arr.get(l,r)<<"\n";
        }
    }

}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}