#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    string s1,s2;
    cin>>s1>>s2;
    set<int>s;
    for(char x:s2) s.insert(x);
    for(int i=1;i<s1.size();i++){
        char x=s1[i];
        if((int)(x)>=60 && (int)(x)<=90){
            if(s.find(s1[i-1])==s.end()){
                cout<<"No\n";
                return ;
            }
        }
    }
    cout<<"Yes\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}
