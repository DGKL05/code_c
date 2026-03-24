#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    string s1;
    cin>>s1;
    int ans = 0;
    int n = s1.size();
    int temp=0;
    for(int i=0;i<n;i++){
        if(s1[i] == 'X'){
            temp = 0;
        }else {
            temp ++;
            ans+=temp;
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