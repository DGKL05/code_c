#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 998244353;

struct Node
{
    ll sum;
    ll val;
    ll lazy;
};

vector<Node> tr;
vector<ll> a;

void pushup(int u)
{
    tr[u].sum = (tr[u << 1].sum + tr[u << 1 | 1].sum) % mod;
    tr[u].val = (tr[u << 1].val + tr[u << 1 | 1].val
                + tr[u << 1].sum * tr[u << 1 | 1].sum) % mod;
}

void apply(int u,int l,int r,ll d)
{
    d %= mod;
    ll len = r - l + 1;
    ll cnt = len * (len - 1) / 2 % mod;

    tr[u].val = (tr[u].val
                + d * ((len - 1) % mod) % mod * tr[u].sum % mod
                + cnt * d % mod * d % mod) % mod;

    tr[u].sum = (tr[u].sum + (len % mod) * d) % mod;
    tr[u].lazy = (tr[u].lazy + d) % mod;
}

void pushdown(int u,int l,int r)
{
    if(tr[u].lazy == 0) return;

    int mid = (l + r) >> 1;
    apply(u << 1,l,mid,tr[u].lazy);
    apply(u << 1 | 1,mid + 1,r,tr[u].lazy);

    tr[u].lazy = 0;
}

void build(int u,int l,int r)
{
    tr[u] = {0,0,0};

    if(l == r){
        tr[u].sum = a[l] % mod;
        return;
    }

    int mid = (l + r) >> 1;
    build(u << 1,l,mid);
    build(u << 1 | 1,mid + 1,r);

    pushup(u);
}

void update(int u,int l,int r,int ql,int qr,ll d)
{
    if(ql <= l && r <= qr){
        apply(u,l,r,d);
        return;
    }

    pushdown(u,l,r);

    int mid = (l + r) >> 1;
    if(ql <= mid) update(u << 1,l,mid,ql,qr,d);
    if(qr > mid) update(u << 1 | 1,mid + 1,r,ql,qr,d);

    pushup(u);
}

Node query(int u,int l,int r,int ql,int qr)
{
    if(ql <= l && r <= qr){
        return tr[u];
    }

    pushdown(u,l,r);

    int mid = (l + r) >> 1;

    if(qr <= mid){
        return query(u << 1,l,mid,ql,qr);
    }else if(ql > mid){
        return query(u << 1 | 1,mid + 1,r,ql,qr);
    }else{
        Node left = query(u << 1,l,mid,ql,qr);
        Node right = query(u << 1 | 1,mid + 1,r,ql,qr);

        Node res;
        res.sum = (left.sum + right.sum) % mod;
        res.val = (left.val + right.val + left.sum * right.sum) % mod;
        res.lazy = 0;

        return res;
    }
}

void test()
{
    int n,q;
    cin>>n>>q;

    a.assign(n + 1,0);
    tr.assign(4 * n + 5,{0,0,0});

    for(int i = 1;i <= n;i++){
        cin>>a[i];
    }

    build(1,1,n);

    while(q--){
        int op,l,r;
        cin>>op>>l>>r;

        if(op == 1){
            ll d;
            cin>>d;
            update(1,1,n,l,r,d);
        }else{
            cout << query(1,1,n,l,r).val << '\n';
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin>>T;
    while(T--) test() ;
    return 0;
}