#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    vector<string>arr;
    for(int i=0;i<n;i++){
        string s1;
        cin>>s1;
        string s2;
        cin>>s2;
        s1+=s2;
        arr.push_back(s1);
        // cout<<s1<<"\n";
    }
    int ans=0;
    for(int i=1;i<n;i++){
        // cout<<arr[i]<<"\n"<<arr[i-1]<<"\n";
        if(arr[i][0] == arr[i-1][1]) ans++;
    }
    cout<<ans<<"\n";
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