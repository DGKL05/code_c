#include<bits/stdc++.h>
using namespace std;
using ll =long long;

set<string>st;

void test()
{
    int n = 0;
    cin>>n;
    bool fa=false;
    for(int i=0;i<n;i++){
        string s1;
        cin>>s1;
        int m=s1.size();
        if(st.find(s1)!=st.end()){
            continue;
        }
        for(int i=0;i<m-2;i++){
            if(s1.substr(i,3) == "bie" && st.find(s1) == st.end()){
                st.insert(s1);
                cout<<s1<<"\n";
                fa=true;
                break;
            }
        }
        
    }
    if(!fa){
        cout<<"Time to play Genshin Impact, Teacher Rice!\n";
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}