#include<bits/stdc++.h>
using namespace std;

void test()
{
        string s1;
        cin>>s1;
        int n=s1.size();
        if(s1.substr(n-12,12)=="isallyouneed"){
            cout<<"Yes\n"<<s1.substr(0,n-12)<<"\n";
        }else{
            cout<<"No\n";
        }
}

int main()
{
        cout<<"Hello world\n";
        int t=1;
        // cin>>t;
        while(t--) test();
        return 0;
}
