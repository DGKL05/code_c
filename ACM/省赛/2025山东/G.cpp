#include<bits/stdc++.h>
using namespace std;
using ll =long long;

struct node{
    ll w;ll t;ll word;
};

bool cmp(const node &a,const node &b){
    return a.word < b.word;
}

void test()
{
    int n=0;ll k=0;
    cin>>n>>k;
    vector<node>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i].w>>arr[i].t;
        arr[i].word = arr[i].t + (k - arr[i].w);qqqqqqqqqqqqqqqqqqqq
    }
    sort(arr.begin() , arr.end() , cmp);
    // for(auto x:arr){qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq
    //     cout<<x.word<<"\n";
    // }
    ll ans = 0;ll last=0;
    for(int i=0;i<n;i++){
        ll time = max(arr[i].word , last + 1);
        last = time;
        ans = time;
    }
    cout<<ans<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}
