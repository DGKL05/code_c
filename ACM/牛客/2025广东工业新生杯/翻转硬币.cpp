#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    string s1;
    cin>>s1;
    int n = s1.size();
    vector<int>idx;
    s1+='1';
    int cnt=0;
    for(int i=0;i<=n;i++){
        if(s1[i]=='0'){
            cnt++;
        }else {
            if(cnt%2==1) idx.push_back(i-1);
            // cout<<i<<"\n";
            cnt=0;
        }
    }

    for(int i=0;i<idx.size();i+=2){
        if((idx[i]+2)!=idx[i+1]){
            cout<<"No\n";
            return ;
        }
    }
    if(idx.size()%2==1){
        cout<<"No\n";
        return ;
    }
    cout<<"Yes\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}