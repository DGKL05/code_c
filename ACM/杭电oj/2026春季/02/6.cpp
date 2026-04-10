#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    set<int>s1;
    for(int i=0;i<n;i++){
        int num=0;
        cin>>num;
        if(num <= n && num >= 1){
            s1.insert(num);
        }
    }
    cout<<s1.size()<<"\n";
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