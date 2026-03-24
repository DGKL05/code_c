#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    string s1;
    cin>>s1;
    int idx=-1;
    for(int i=0;i<n-1;i++){
        if((int)(s1[i+1]-'a') < (int)(s1[i]-'a')){
            idx=i;
            break;
        }
    }
    if(idx==-1){
        cout<<s1<<"\n";
        return ;
    }
    int idx2=-1;
    for(int i=idx+1;i<n;i++){
        if((int)(s1[idx]-'a') < (int)(s1[i]-'a')){
            idx2=i;
            break;
        }
    }
    if(idx2==-1){
        for(int i=0;i<idx;i++) cout<<s1[i];
        for(int i=idx+1;i<n;i++) cout<<s1[i];
        cout<<s1[idx]<<"\n";
        return ;
    }
    for(int i=0;i<idx;i++) cout<<s1[i];
    for(int i=idx+1;i<idx2;i++) cout<<s1[i];
    cout<<s1[idx];
    for(int i=idx2;i<n;i++)cout<<s1[i];
    cout<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}