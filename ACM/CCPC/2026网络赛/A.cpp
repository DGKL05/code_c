#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int INF = -1000000000;

struct node{
    int k;
    int type;
    vector<int>a;
    vector<int>b;

    node(int k1,int type1):k(k1),type(type1),a(k1+1),b(k1+1){
        if(type == 0){
            fill(a.begin(),a.end(),0);
        }else{
            fill(a.begin(),a.end(),INF);
        }
        fill(b.begin(),b.end(),INF);
    }

    void add(int x){
        if(type == 0){
            for(int i=k;i>=1;i--){
                int num = a[i];
                b[i] = max(b[i],num-x);
                a[i] = max(a[i],b[i-1]+x);
            }
            b[0] = max(b[0],-x);
        }else{
            for(int i=k;i>=1;i--){
                int num = a[i];
                if(num > INF/2){
                    b[i] = max(b[i],num-x);
                }
                a[i] = max(a[i],b[i-1]+x);
                a[i] = max(a[i],x);
            }
            int num = a[0];
            if(num > INF/2){
                b[0] = max(b[0],num-x);
            }
            a[0] = max(a[0],x);
        }
    }
};

void test(){
    int n,k,q;
    cin>>n>>k>>q;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    int B = max(1,15*n/100);
    int cnt = (n+B-1)/B;
    vector<pair<int,int>>qry(q);
    vector<int>ans(q,0);
    vector<int>ord(q);
    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        if(r < l) r += n;
        qry[i] = {l,r};
        ord[i] = i;
    }
    sort(ord.begin(),ord.end(),[&](int x,int y){
        return qry[x].second < qry[y].second;
    });
    vector<vector<int>>g(cnt);
    for(auto id:ord){
        int idx = (qry[id].first-1)/B;
        g[idx].push_back(id);
    }
    int len = k+1;
    vector<int>dp((ll)B*len);
    auto get = [&](int x){
        return a[(x-1)%n+1];
    };
    for(int z=0;z<cnt;z++){
        if(g[z].empty()) continue;
        int l = z*B+1;
        int mid = min(n,(z+1)*B);
        int mxr = qry[g[z].back()].second;
        for(int type=0;type<2;type++){
            int lim = k;
            if(type == 1) lim = k-1;
            if(lim < 0) continue;
            node left(lim,type);
            for(int i=mid;i>=l;i--){
                left.add(-get(i));
                int *p = dp.data()+(ll)(i-l)*len;
                for(int j=0;j<=lim;j++){
                    p[j] = left.a[j];
                }
            }
            node right(lim,type);
            int idx = 0;
            for(int i=mid;i<=mxr;i++){
                if(i > mid) right.add(get(i));
                while(idx < g[z].size() && qry[g[z][idx]].second == i){
                    int id = g[z][idx];
                    int *p = dp.data()+(ll)(qry[id].first-l)*len;
                    int res = ans[id];
                    for(int j=0;j<=lim;j++){
                        res = max(res,p[j]+right.a[lim-j]);
                    }
                    ans[id] = res;
                    idx++;
                }
            }
        }
    }
    for(int i=0;i<q;i++){
        cout<<ans[i]<<"\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin>>T;
    while(T--) test();
    return 0;
}