#include<bits/stdc++.h>
using namespace std;

using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    vector<int>v1(26);
    for(int i=0;i<26;i++){
        cin>>v1[i];
    }
    string s1;
    cin>>s1;
    bool fa=true;
    int num=1;
    for(char x:s1){
        if(v1[(int)(x-97)]==0){
            cout<<"No\n";
            return ;
        }
    }
    for(int i=0;i<n-1;i++){
        if(s1[i+1]==s1[i]) num++;
        else {
            if(num%v1[(int)(s1[i]-97)]!=0){
                cout<<"No\n";
                return ;
            }
            num=1;
        }
    }
    num=1;
    for(int i=n-2;i>=0;i--){
        if(s1[i]==s1[n-1]) num++;
        else {
            break;
        }
    }
    // cout<<num<<"\n";
    if(num%v1[(int)(s1[n-1]-97)]!=0){
        cout<<"No\n";
        return ;
    }
    cout<<"Yes\n";
}

int main()
{
    int T=1;
    // cout<<(int)('z'-97)<<"\n";
    cin>>T;
    while(T--) test();
    return 0;
}