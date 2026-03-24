#include<bits/stdc++.h>
using namespace std;
using ll =long long;

int n;int m;
string S;
string T;
map<char,int>map_s;
map<char,int>map_x;

void test()
{
    string s1;
    cin>>s1;
    bool fa1 = true;
    bool fa2 = true;
    for(auto x : s1){
        if(map_s.find(x) == map_s.end()){
            fa1 = false;
        }
    }
    for(auto x : s1){
        if(map_x.find(x) == map_x.end()){
            fa2 = false;
        }
    }
    if(fa1 && fa2){
        cout<<"Unknown\n";
    }else cout<<(fa1 ? "Takahashi\n" : "Aoki\n" );
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m>>S>>T;
    for(auto x:S){
        map_s[x] = 1;
    }
    for(auto x:T){
        map_x[x] = 1;
    }
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}