#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    string s1;
    cin>>s1;
    int sz = s1.size();
    int n=0;
    cin>>n;
    for(int i=0;i<n;i++){
        int l=0;int r=0;string a;string b;
        cin>>l>>r>>a>>b;
        l--;r--;
        string temp = s1.substr(l , (r - l + 1));
        // cout<<temp<<"\n";
        // cout<<s1<<" ";
        s1.erase(l , (r - l + 1));
        string ab = a+b;
        int n1 = ab.size();
        bool fa = false;
        for(int i=0;i<s1.size();i++){
            if((i + n1) >= s1.size()) break;
            if(s1.substr(i , n1) == ab){
                fa = true;
                // cout<<s1[i + a.size()]<<"\n";
                s1.insert(i + a.size() , temp);
                break;
            }
        }
        if(fa == false) s1+=temp;
        // cout<<s1.size()<<"\n";
    }
    cout<<s1<<"\n";
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