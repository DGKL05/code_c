#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;int k=0;
    cin>>n>>k;
    string s1;
    cin>>s1;
    int ans=0;
    sort(s1.begin(),s1.end());
    // cout<<s1<<'\n';
    int num1=0;int num0=0;
    for(int i=0;i<n;i++){
        if(s1[i]=='0'){
            num0++;
        }else{
            num1++;
        }
    }
    int max_num=max({n/2-num1,n/2-num0});
    int min_num=min(num1/2+num0/2,n/2);
    
    if(k>min_num || k<max_num){
        cout<<"NO\n";
    }else{
        if((num1-k+n/2)%2==0 && (num0-k+n/2)%2==0){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}
