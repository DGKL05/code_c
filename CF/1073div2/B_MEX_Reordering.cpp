#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n = 0;
    cin>>n;
    int a=0;int b=0;
    for(int i=0;i<n;i++){
        int num = 0;
        cin>>num;
        if(num == 0) a++;
        if(num == 1) b++;
    }
    if(n == 2){
        if(a == 1) {
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
        return ;
    }
    if(a == 1){
        cout<<"YES\n";
        return ;
    }
    if(a == 0){
        cout<<"NO\n";
        return ;
    }
    if(b != 0){
        cout<<"YES\n";
        return ;
    }
    cout<<"NO\n";
}
/*

*/
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