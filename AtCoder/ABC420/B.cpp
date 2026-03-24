#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;int m=0;
    cin>>n>>m;
    vector<int>v1(n);
    vector<string>arr;
    for(int i=0;i<n;i++){
        string s1;
        cin>>s1;
        arr.push_back(s1);
    }
    for(int i=0;i<m;i++){
        int num1=0;int num0=0;
        for(int j=0;j<n;j++){
            if(arr[j][i]=='1') num1++;
            else num0++;
        }
        if(num1==0 || num0==0) continue;
        char temp='2';
        if(num1>num0) temp='0';
        else temp='1';
        // cout<<temp<<"\n";
        for(int j=0;j<n;j++){
            if(arr[j][i]==temp) v1[j]++;
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,v1[i]);
    }
    for(int i=0;i<n;i++){
        if(v1[i]==ans) cout<<(i+1)<<" ";
    }
    cout<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}