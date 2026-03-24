#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    multiset<int>s1;
    int n=0;
    cin>>n;
    for(int i=0;i<n;i++){
        int op=0;
        cin>>op;
        if(op==1){
            int num=0;
            cin>>num;
            s1.insert(num);
        }else {
            auto it=s1.begin();
            cout<<*it<<"\n";
            s1.erase(it);
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}