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
vector<int> valid_steps; // 新增：记录合法步骤编号

// 标准化边的顺序
P make_edge(node a, node b) {
    if (a.x < b.x || (a.x == b.x && a.y < b.y)) return {a, b};
    return {b, a};
}

// 检查两点是否相邻
bool is_adjacent(node a, node b) {
    return (abs(a.x - b.x) + abs(a.y - b.y)) == 1;
}

// 检查坐标是否越界
bool in_board(node a, int n, int m) {
    return a.x >= 1 && a.x <= n && a.y >= 1 && a.y <= m;
}

// 检查所有合法边是否都被画上
bool all_edges_drawn(int n, int m) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            node a = {i, j};
            if (i < n) {
                node b = {i + 1, j};
                if (s1.find(make_edge(a, b)) == s1.end()) return false;
            }
            if (j < m) {
                node b = {i, j + 1};
                if (s1.find(make_edge(a, b)) == s1.end()) return false;
            }
        }
    }
    return true;
}

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
        node a={a1,b1};
        node b={a2,b2};
        // 合法性补充判断
        if(!in_board(a, n, m) || !in_board(b, n, m)) { v1.push_back(i); continue; }
        if(!is_adjacent(a, b)) { v1.push_back(i); continue; }
        if(s1.find(make_edge(a, b)) != s1.end()) { v1.push_back(i); continue; }
        if(!check()) { v1.push_back(i); continue; }
        // 合法步骤
        valid_steps.push_back(i);
        s1.insert(make_edge(a, b));
        move();
    }
    // 游戏结束判定
    if(!all_edges_drawn(n, m)) {
        cout << "-1\n";
    } else if(!v1.empty()) {
        cout << "-1\n";
    } else {
        for(size_t i=0;i<valid_steps.size();++i) {
            if(i) cout << " ";
            cout << valid_steps[i];
        }
        cout << "\n";
    }
    if(xiao_a>xiao_b){
        cout<<"0 "<<xiao_b<<"\n";
    }else cout<<"1 "<<xiao_a<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}