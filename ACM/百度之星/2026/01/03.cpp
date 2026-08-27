#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct Graph{
    int n;
    vector<int>h,e;

    void read(int _n){
        n = _n;
        vector<int>d(n+1),u(n-1),v(n-1);
        for(int i=0;i<n-1;i++){
            cin>>u[i]>>v[i];
            d[u[i]]++;
            d[v[i]]++;
        }
        h.assign(n+2,0);
        for(int i=1;i<=n;i++) h[i+1] = h[i] + d[i];
        e.resize(2*n-2);
        vector<int>cur = h;
        for(int i=0;i<n-1;i++){
            e[cur[u[i]]++] = v[i];
            e[cur[v[i]]++] = u[i];
        }
    }
};

struct Seg{
    int n;
    vector<int>mi,cnt,lz;

    void pushup(int p){
        int l = p<<1,r = l|1;
        mi[p] = min(mi[l],mi[r]);
        cnt[p] = 0;
        if(mi[l] == mi[p]) cnt[p] += cnt[l];
        if(mi[r] == mi[p]) cnt[p] += cnt[r];
    }

    void tag(int p,int x){
        mi[p] += x;
        lz[p] += x;
    }

    void pushdown(int p){
        if(!lz[p]) return;
        tag(p<<1,lz[p]);
        tag(p<<1|1,lz[p]);
        lz[p] = 0;
    }

    void build(int p,int l,int r,vector<int>&a){
        if(l == r){
            mi[p] = a[l];
            cnt[p] = 1;
            return;
        }
        int mid = (l+r)>>1;
        build(p<<1,l,mid,a);
        build(p<<1|1,mid+1,r,a);
        pushup(p);
    }

    void init(vector<int>&a){
        n = a.size()-1;
        mi.assign(4*n+5,0);
        cnt.assign(4*n+5,0);
        lz.assign(4*n+5,0);
        build(1,1,n,a);
    }

    void add(int p,int l,int r,int ql,int qr,int x){
        if(ql <= l && r <= qr){
            tag(p,x);
            return;
        }
        pushdown(p);
        int mid = (l+r)>>1;
        if(ql <= mid) add(p<<1,l,mid,ql,qr,x);
        if(qr > mid) add(p<<1|1,mid+1,r,ql,qr,x);
        pushup(p);
    }

    void add(int l,int r,int x){
        if(l > r) return;
        add(1,1,n,l,r,x);
    }
};

struct Node{
    int u,fa,id,bi,son,sbi;
    bool ok;
};

void test(){
    int n=0;
    cin>>n;

    Graph g1,g2;
    g1.read(n);
    g2.read(n);

    vector<int>fa(n+1),dfn(n+1),sz(n+1,1),ord;
    ord.reserve(n);

    vector<int>st;
    st.reserve(n);
    st.push_back(1);

    while(!st.empty()){
        int u = st.back();
        st.pop_back();

        dfn[u] = ord.size()+1;
        ord.push_back(u);

        for(int i=g1.h[u];i<g1.h[u+1];i++){
            int v = g1.e[i];
            if(v == fa[u]) continue;
            fa[v] = u;
            st.push_back(v);
        }
    }

    for(int i=n-1;i>=1;i--){
        int u = ord[i];
        sz[fa[u]] += sz[u];
    }

    auto in = [&](int u,int v){
        return dfn[u] <= dfn[v] && dfn[v] < dfn[u]+sz[u];
    };

    vector<int>f(n+1),a(n+1);

    for(auto u:ord){
        f[u] = 1;
        if(fa[u]) f[u] += f[fa[u]];

        for(int i=g2.h[u];i<g2.h[u+1];i++){
            int v = g2.e[i];
            if(in(v,u)) f[u]--;
        }

        a[dfn[u]] = f[u];
    }

    auto cmp = [&](int x,int y){
        return dfn[x] < dfn[y];
    };

    for(int u=1;u<=n;u++){
        sort(g1.e.begin()+g1.h[u],g1.e.begin()+g1.h[u+1],cmp);
        sort(g2.e.begin()+g2.h[u],g2.e.begin()+g2.h[u+1],cmp);
    }

    Seg tr;
    tr.init(a);

    auto addtree = [&](int u,int x){
        tr.add(dfn[u],dfn[u]+sz[u]-1,x);
    };

    auto move = [&](int u,int v,int x,int bi){
        addtree(v,-x);

        int ed = g2.h[u+1];

        while(bi < ed && dfn[g2.e[bi]] < dfn[v]+sz[v]){
            int w = g2.e[bi];
            if(dfn[w] >= dfn[v]) addtree(w,x);
            bi++;
        }

        addtree(1,x);
        addtree(v,-x);

        for(int i=g2.h[v];i<g2.h[v+1];i++){
            int w = g2.e[i];

            if(in(v,w)) continue;

            if(w == u){
                addtree(v,x);
                addtree(1,-x);
            }
            else if(in(w,u)){
                int l = g1.h[w];
                int r = g1.h[w+1]-1;

                while(l < r){
                    int mid = (l+r+1)>>1;
                    if(dfn[g1.e[mid]] <= dfn[u]) l = mid;
                    else r = mid-1;
                }

                int t = g1.e[l];
                addtree(t,x);
                addtree(1,-x);
            }
            else{
                addtree(w,-x);
            }
        }

        return bi;
    };

    ll ans = 0;

    vector<Node>s;
    s.reserve(n);

    s.push_back({
        1,0,g1.h[1],g2.h[1],-1,0,false
    });

    while(!s.empty()){
        Node &now = s.back();

        if(!now.ok){
            ans += tr.cnt[1];
            now.ok = true;
        }

        if(now.son != -1){
            now.bi = move(now.u,now.son,-1,now.sbi);
            now.son = -1;
            continue;
        }

        int ed = g1.h[now.u+1];

        while(now.id < ed && g1.e[now.id] == now.fa) now.id++;

        if(now.id == ed){
            s.pop_back();
            continue;
        }

        int v = g1.e[now.id++];
        int bi = now.bi;

        move(now.u,v,1,bi);

        now.son = v;
        now.sbi = bi;

        s.push_back({
            v,now.u,g1.h[v],g2.h[v],-1,0,false
        });
    }

    cout<<(ans-n)/2+n<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T = 1;
    cin>>T;

    while(T--) test();

    return 0;
}