#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void test()
{
    cout<<(int)('z' - 'a')<<"\n";
    int n=0;
    cin>>n;
    string s1;
    cin>>s1;
    if(s1.size() == n) {
        cout<<s1<<"\n";
    }else {
        for(int i=0;i<n - s1.size() ; i++) cout<<"o";
        cout<<s1<<"\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T=1;
    // cin>>T;
    while(T--) test();
    return 0;
}