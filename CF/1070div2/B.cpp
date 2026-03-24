#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n = 0;
    cin>>n;
    string s1;
    cin>>s1;
    int ans = 0;
    int first_one = 0;
    int end_one = 0;
    for(int i=0;i<n;i++){
        if(s1[i] != '1') first_one++;
        else break;
    }
    
    for(int i=n-1;i>=0;i--){
        if(s1[i] != '1') end_one++;
        else break;
    }
    ans = first_one + end_one;
    int pre_one=first_one;
    int num = 0;
    for(int i=first_one;i<n;i++){
        if(s1[i] == '0') num++;
        else {
            ans = max(ans , num);
            num = 0;
        }
    }
    cout<<ans<<"\n";
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