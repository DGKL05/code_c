#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int ans = 0;
    int num = 0;
    bool fa = false;
    cin>>num;
    for(int i=0;i<num ;i++){
        int q=0;
        cin>>q;
        if(q == 1){
            ans++;
        }else if(q == 2){
            if(ans>=1) ans--;
        }else {
            fa = !fa;
        }
        cout<<((ans>=3 && fa) ? "Yes\n" : "No\n");
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