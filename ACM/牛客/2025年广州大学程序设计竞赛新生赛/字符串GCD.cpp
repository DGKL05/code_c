#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    string a,b;
    cin>>a>>b;
    set<char>s1;
    set<char>st;
    for(int i=0;i<2;i++){
        s1.insert(a[i]);
    }
    for(int i=0;i<2;i++){
        if(s1.find(b[i]) != s1.end() && st.find(b[i]) == st.end()){
            st.insert(b[i]);
            cout<<b[i];
        }
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