#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;int l=0;int r=0;
    cin>>n>>l>>r;
    int ans=-1;int idx=-1;
    for(int i=1;i<=n;i++){
        int num=0;
        cin>>num;
        if(num >= l && num <= r){
            if(num > ans){
                ans = num ;
                idx = i;
            }
        }
    }
    cout<<idx<<"\n";
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