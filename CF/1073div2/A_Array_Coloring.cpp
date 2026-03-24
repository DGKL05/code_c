#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    vector<int>arr(n);
    set<int>ji,er;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(i & 1) er.insert(arr[i]);
        else ji.insert(arr[i]);
    }
    sort(arr.begin() , arr.end());
    for(int i=0;i<n - 1;i++){
        if(er.find(arr[i]) != er.end() && er.find(arr[i+1]) != er.end()){
            cout<<"NO\n";
            return ;
        }
        if(ji.find(arr[i]) != ji.end() && ji.find(arr[i+1]) != ji.end()){
            cout<<"NO\n";
            return ;
        }
    }
    cout<<"YES\n";
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