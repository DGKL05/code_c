#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    vector<int>arr(n);
    map<int,int>m1;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        m1[arr[i]] = i;
    }
    auto it = m1.end();
    it--;
    for(int i=0;i<n;i++){
        if( it->first == arr[i] ) {
            it--;
            continue;
        }
        int idx = i;
        int idx2 = it->second;
        while(idx <= idx2){
            swap(arr[idx] , arr[idx2]);
            idx++;
            idx2--;
        }
        for(auto x:arr) cout<<x<<" ";
        cout<<"\n";
        return ;
    }
    // cout<<"\n";
    for(auto x:arr) cout<<x<<" ";
    cout<<"\n";
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
