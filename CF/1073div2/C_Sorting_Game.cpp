#include<bits/stdc++.h>
using namespace std;
using ll =long long;
/*
    101010
    011010

*/
void test()
{
    int n=0;
    cin>>n;
    string s1;
    cin>>s1;
    int num=0;
    int num_0=0;
    vector<int>ans;
    // int num_1=0;
    for(int i=0;i<n;i++){
        if(num != 0 && s1[i] == '0') num_0++,ans.push_back(i+1);;
        if(s1[i] == '1'&& num_0 == 0){
            num++;
            ans.push_back(i+1);
        }
    }
    if(num >= num_0 && num != 0){
        cout<<"Alice\n";
        cout<<ans.size()<<"\n";
        for(auto x : ans){
            cout<<x<<" ";
        }
        cout<<"\n";
    }else cout<<"Bob\n";
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