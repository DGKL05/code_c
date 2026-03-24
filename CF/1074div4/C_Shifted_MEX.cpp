#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    set<ll>s1;
    vector<ll>arr;
    for(int i=0;i<n;i++){
        ll num=0;
        cin>>num;
        if(s1.find(num) == s1.end()){
            s1.insert(num);
            arr.push_back(num);
        }
    }
    sort(arr.begin() , arr.end());
    // for(auto x:arr){
    //     cout<<x<<"\n";
    // }cout<<"end\n";
    int ans=1;
    int temp=arr[0];
    int tans=1;
    n = arr.size();
    for(int i=1;i<n;i++){
        ans = max ( tans , ans );
        if(arr[i] - 1 == temp){
            tans++;
        }else {
            tans=1;
        }
        temp = arr[i];
    }
    ans = max ( tans , ans );
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