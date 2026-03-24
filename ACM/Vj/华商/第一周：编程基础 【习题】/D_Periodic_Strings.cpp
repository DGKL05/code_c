#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    string s1;
    cin>>s1;
    int n = s1.size();
    int ans = n;
    for(int k=1;k<=n;k++){
        string temp = s1.substr(0,k);
        // cout<< temp << "\n";
        if(n % k != 0) continue ;
        bool fa = true;
        for(int i=0;i<n;i += k){
            if(temp != s1.substr(i,k)){
                fa = false;
                break;
            }
        }
        if( fa ) ans = min(ans,k);
    }
    cout<< ans;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T=1;
    cin>>T;
    while(T--) {
        getchar();
        test(); 
        cout<<"\n";
        if(T) cout<<"\n";
    }
    return 0;
}