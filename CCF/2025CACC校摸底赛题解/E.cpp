#include<bits/stdc++.h>
using namespace std;
using ll =long long;

struct DSU {
    int n;
    vector<int>pre;
    DSU (int n){
        pre.resize(n+1);
        for(int i=0;i<=n;i++) pre[i] = i;
    }
    int find(int x){
        return pre[x] == x ? x : find(pre[x]);
    }
    void unid (int a,int b){
        a = find(a);
        b = find(b);
        if(a == b) return ;
        pre[a] = b;
    }
    bool check(int a,int b){
        return find(a) == find(b) ? true : false;
    }
};

void test()
{
    int n=0;int m=0;
    cin>>n>>m;
    DSU dsu(n);
    for(int i=0;i<m;i++){
        char op;int a;int b;
        cin>>op>>a>>b;
        if(op == 'M') dsu.unid(a,b);
        else cout<< (dsu.check(a,b) == true ? "Yes" : "No") <<"\n";
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}