#include<bits/stdc++.h>
using namespace std;
using ll = long long ;

void test()
{
    int n=0;
    cin>>n;
    set<int>s1;
    for(int i=0;i<n;i++){
        int num=0;
        cin>>num;
        s1.insert(num);
    }
    cout<<s1.size()<<"\n";
}

int main()
{
    int t=1;
    cin>>t;
    while(t--) test();
    return 0;
}