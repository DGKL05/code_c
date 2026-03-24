#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void test()
{
    string s1;
    int idx=1;
    vector<vector<int>>arr(3);
    getchar();
    while( s1 != "#:"){
        getline(cin,s1);
        if(s1 == "#:"){
            break;
        }
        string temp;
        int token=0;
        int n1=s1.size();
        for(int i=2;i<n1;i++){
            char x = s1[i];
            // cout<<x;
            if(x=='!' || x=='?'||x=='.'||x==','){
                token++;
                if(temp!="") token++;
                temp="";
                continue;
            }else if(x == ' '){
                if(temp!="") token++;
                temp="";
            }
            else temp+=x;
        }
        if(temp!="") token++;
        arr[idx].push_back(token);
        if(idx == 1) idx=2;
        else idx = 1;
    }
    ll ans1=0;ll ans2=0;int n2 = arr[2].size();
    ll temp=0;
    ll temp1=0;
    // int n1=min((int)arr[1].size(),n2);
    int n1 = arr[1].size()-1;
    for(int i=0;i<n1;i++){
        ans1+=ans1+temp+temp1;
        temp+=arr[1][i];
        temp1+=arr[2][i];
    }
    
    for(int i=0;i<n2;i++){
        ans2+=arr[2][i];
    }
    cout<<ans1<<" "<<ans2<<"\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    // cin>>T;
    while(T--) test();
    return 0;
}