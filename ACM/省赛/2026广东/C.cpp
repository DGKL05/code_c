#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n =0 ;
    cin>>n;
    string s1;
    cin>>s1;
    int num_0=0;
    for(auto x:s1){
        if(x=='0') num_0++;
    }
    if(num_0 != 0){
        for(int i=0;i<n-1;i++){
            cout<<"&";
        }
    }else {
        cout<<"^";
        for(int i=0;i<n-2;i++){
            cout<<"&";
        }
    }
    
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