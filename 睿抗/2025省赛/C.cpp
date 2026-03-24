#include<bits/stdc++.h>
using namespace std;
using ll =long long;

int idx=-1;int a1,a2,b1,b2;int k=0;
int dang=0;int xiao_a=0;int xiao_b=0;
struct node{
    int x;int y;
}; 
using P = pair<node,node>;
bool operator<(const P &a, const P &b){
    if(a.first.x == b.first.x) return a.first.y>b.first.y;
    return a.first.x>b.first.x;
}

set<P>s1;

bool check(){
    // cout<<dang<<" "<<k<<" "<<idx<<"\n";
    if(dang != idx) return false;
    if(a1 == a2 && b1 == b2) return false;
    if(a1 == a2 || b1 == b2) return true;
    else return false;
}

void move(){
    if(a1 == a2){
        if(((s1.find({{a1,b1},{a1-1,b1}})!=s1.end()) && (s1.find({{a2,b2},{a2-1,b2}})!=s1.end()) && (s1.find({{a1-1,b1},{a2-1,b2}})!=s1.end())) || (s1.find({{a1+1,b1},{a1,b1}})!=s1.end() && s1.find({{a2+1,b2},{a2,b2}})!=s1.end() && s1.find({{a1+1,b1},{a2+1,b2}})!=s1.end())) {
            // cout<<"jin\n";cout<<k<<" : \n";
            // cout<<"dang="<<dang<<"\n";
            // cout<<a1<<" "<<b1<<" "<<a2<<" "<<b2<<"\n";
            cout<<(int)(s1.find({{a1+1,b1},{a1,b1}})!=s1.end() && s1.find({{a2+1,b2},{a2,b2}})!=s1.end() && s1.find({{a1+1,b1},{a2+1,b2}})!=s1.end())<<"\n";
            for(auto [l,r]:s1){
                cout<<l.x<<" "<<l.y<<" "<<r.x<<" "<<r.y<<"\n";
            }
            if(!dang) {
                xiao_a++;
            }
            else xiao_b++;
            return ;
        }
        // cout<<"dang="<<dang<<"\n";
        // if(!dang) dang=1;
        // else dang=0;
    }else if(b1 == b2){
        if((s1.find({{a1,b1-1},{a1,b1}})!=s1.end() && s1.find({{a2,b2-1},{a2,b2}})!=s1.end() && s1.find({{a1,b1-1},{a2,b2-1}})!=s1.end()) || (s1.find({{a1,b1+1},{a1,b1}})!=s1.end() && s1.find({{a2,b2+1},{a2,b2}})!=s1.end() && s1.find({{a1,b1+1},{a2,b2+1}})!=s1.end())){
            // cout<<"jin\n";cout<<k<<"\n";
            // for(auto [l,r]:s1){
            //     cout<<l.x<<" "<<l.y<<"\n";
            // }
            if(!dang) {
                xiao_a++;
            }
            else xiao_b++;
            return ;
        }
        // cout<<"dang="<<dang<<"\n";
        // if(!dang) dang=1;
        // else dang=0;
    }
    // cout<<"dang="<<dang<<"\n";
    if(!dang) dang=1;
    else dang=0;
}

void test()
{
    int n=0;int m=0;int s=0;
    cin>>n>>m>>s;
    vector<int>v1;
    for(int i=1;i<=s;i++){
        k=i;
        cin>>idx>>a1>>b1>>a2>>b2;
        if(check() ){
            node a={a1,b1};
            node b={a2,b2};
            s1.insert({a,b});
            s1.insert({b,a});
            move();
            
        }else {
            v1.push_back(i);
        }
    }
    if(v1.size() == 0){
        cout<<"-1\n";
    }else {
        for(auto x : v1) cout<<x<<" ";
        cout<<"\n";
    }
    if(xiao_a>xiao_b){
        cout<<"0 "<<xiao_a<<"\n";
    }else cout<<"1 "<<xiao_b<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}