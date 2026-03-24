#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    map<int,int>m1;
    for(int i=0;i<n;i++){
        int num = 0;
        cin>>num;
        m1[num] = i+1;
    }
    auto it = m1.begin();
    for(int i=0;i<3;i++){
        cout<<it->second<<" ";
        it++;
    }
    cout<<"\n";
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