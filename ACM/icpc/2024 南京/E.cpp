#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    string ans = "nanjing";
    int n = 0;ll k =0;
    cin>>n>>k;
    string s1;
    cin>>s1;
    int num = 0;
    if(n<7){
        cout<<"0\n";
        return ;
    }
    s1+=s1.substr(0,min((ll)7,k));
    for(int i=0;i<n;i++){
        if(s1.substr(i,7) == ans) {
            num++;
            // cout<<s1.substr(i,7)<<"\n";
        }
    }
    
    cout<<num<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}