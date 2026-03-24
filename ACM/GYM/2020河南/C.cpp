#include<bits/stdc++.h>
using namespace std;
const int N = 2e3+5;
using ll =long long;
struct node{
    double x,y;ll hp;int id;
};

int idx;
bool v[N];
bool vv[N];
void solve(){
    int n;cin>>n;
    vector<node>arr;
    for(int i = 1;i<=n;++i){
        int op;cin>>op;
        if(op==1){
            double x,y;ll h;cin>>x>>y>>h;
            arr.push_back({x,y,h,i});
        }else{
            double x,y,r;ll atk;cin>>x>>y>>atk>>r;
            vv[i]=1;
            if(arr.size()==0){vv[i] = 1;continue;}
            double x1=x,y1=y;ll d1 = 1e18;
            for(int j = 0;j<arr.size();j++){
                auto [x2,y2,hp,id] = arr[j];
                if(hp<=0)continue;
                ll d = (x-x2)*(x-x2)+(y-y2)*(y-y2);
                cout<<d<<' ';
                if(d<d1){x1 = x2,y1 = y2;d1 = d;}
            }
            //cout<<i<<' '<<x1<<' '<<y1<<' '<<endl;
            for(int j = 0;j<arr.size();j++){
                auto [x2,y2,hp,id] = arr[j];
                if(hp<=0)continue;
                ll d = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
                // cout<<d<<'\n';
                if(d<=r*r){
                    arr[j].hp -= 3*atk;
                    if(arr[j].hp>0)vv[i]=0;
                }
            }
            // for(int j = 0;j<arr.size();++j){
            //     auto [x2,y2,hp,id] = arr[j];
            //     cout<<i<<' '<<x2<<' '<<y2<<' '<<hp<<endl;
            // }
        }
        
    }
    for(int i = 0;i<arr.size();i++){
        if(arr[i].hp<=0)vv[arr[i].id]=0;
        else vv[arr[i].id]=1;
    }
    for(int i = 1;i<=n;i++){
        if(vv[i])cout<<"Yes\n";
        else cout<<"No\n";
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    //cin>>t;
    while(t--)solve();
}