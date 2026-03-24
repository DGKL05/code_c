#include<bits/stdc++.h>
using namespace std;
using ll =long long;
const int N = 2*1e5+5;
int pre[N];

int find(int x){
    return pre[x] == x ? x : pre[x] = find(pre[x]) ;
}

void untin(int x,int y){
    int x1=find(x);
    int y1=find(y);
    pre[y1] = x1;
}

int main()
{
    int n=0;int m=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++) pre[i] = i;
    for(int i=0;i<m;i++){
        int op=0;int x=0;int y=0;
        cin>>op>>x>>y;
        if(op == 1) untin(x,y);
        else {
            if(find(x) == find(y)){
                cout<<"YES\n";
            }else{
                cout<<"NO\n";
            }
        }
    }
    return 0;
}