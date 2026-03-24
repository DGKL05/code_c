#include<bits/stdc++.h>
using namespace std;
using ll =long long;

struct node{
    int x;int y;
};

void test()
{
    int n =0;int m=0;int k=0;
    cin>>n>>m>>k;
    // set<string>s1;
    map<string,vector<node>>m1;
    for(int i=0;i<n;i++){
        for(int j =0;j<m;j++){
            char v1[k];
            for(int t=0;t<k;t++){
                cin>>v1[t];
            }
            string temp =v1;
            sort(temp.begin(),temp.end());
            node a={i,j};
            m1[temp].push_back(a);
        }
    }
    for(auto [l,r] : m1){
        if(r.size() == 1){
            cout<<r[0].x+1<<" "<<r[0].y+1<<"\n";
            return ;
        }
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