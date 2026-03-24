#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+10;
int n , m ;
struct node{
    int l , r , p = 0 , idx;
    ll mav , miv;
}tree[N << 2];

struct xd{
    int l , r;
    ll sum;
}te[N<<2];

ll a[N];

void pushup(int u){
    te[u].sum = (te[u << 1].sum + te[u << 1 |1 ].sum);
}

void build(int u ,int l ,int r){
    te[u].l = l , te[u].r = r;
    if(l == r){
        te[u].sum = a[l];
        return;
    }
    int mid = (l + r ) >> 1;
    build(u << 1 , l , mid);
    build(u << 1 |1, mid + 1, r);
    pushup(u);
}

void modify(int u , int x , ll v){
    if(te[u].l == te[u].r && te[u].l == x){
        te[u].sum = v;
        return;
    }
    int mid = (te[u].l + te[u].r) >> 1;
    if(x <= mid) modify(u << 1,  x , v);
    else modify(u << 1 |1, x , v);
    pushup(u);
}

ll query(int u , int l ,int r){
    if(l <= te[u].l &&  te[u].r <= r) return te[u].sum;
    ll res = 0;
    int mid = (te[u].l + te[u].r) >> 1;
    if(l <= mid) res += query ( u << 1 , l ,r);
    if(r > mid) res += query(u << 1|1 , l,r);
    return res;
}

void pushupTree(int idx){
    int l = tree[idx].l  , r = tree[idx].r;
    tree[idx].mav = max(tree[l].miv  , tree[r].miv);
    tree[idx].miv = min(tree[l].miv  , tree[r].miv);
    modify(1 , idx - n , tree[idx].mav );
}

void test(){
    int  k , idx = 1;
    cin >> n >> m;
    queue <node> que;
    for(int i = 1 ; i<= n ;i++){
        cin >> k;
        tree[idx].mav = k , tree[idx].miv = k;
        tree[idx].idx = idx;
        que.push(tree[idx++]);
    }
    
    while(que.size() > 1){
        auto x = que.front() ; que.pop();
        auto y = que.front() ; que.pop();
        tree[idx].idx = idx;
        tree[idx].l = x.idx , tree[idx].r = y.idx;
        tree[x.idx].p = idx ,  tree[y.idx].p = idx;
        tree[idx].mav = max(x.miv , y.miv);
        tree[idx].miv = min(x.miv , y.miv);
        que.push(tree[idx]);
        idx ++;
    }
    for(int i = 1 , k = n +1 ; i < n ; i++ , k++ ){
        a[i] = tree[k].mav;
    }
    build(1, 1 , n-1);
    for(int i = 1 ;i <= m ;i++){
        char op;
        int l ,r;
        cin >> op >> l >> r;
        if(op == 'A'){
            ll ans = 0;
//             if(l > 1) ans = query(1 ,1 , r) - query ( 1 , 1, l-1);
//             else ans = query(1 , 1 , r);
            ans = query(1 , l, r);
            cout << ans << "\n";
        }else{
            ll tmp;
            tmp = tree[l].mav;
            tree[l].miv = tree[l].mav = tree[r].miv;
            tree[r].miv = tree[r].mav = tmp;
            int p = tree[l].p;
//             cout << "xiugai " << l << " " << r << "\n";
//             cout << "l 的p \n" << p << "\n"; 
            while(p != 0){
                pushupTree(p);
                p = tree[p].p ;
//                 cout << p << "\n"; 
            }
            p = tree[r].p;
//             cout << "r 的p \n" << p << "\n"; 
            while(p != 0){
                pushupTree(p);
                p = tree[p].p ;
//                 cout << p <<"\n";
            }
        }
    }
    
}

int main(){
   ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    test();
   return 0;  
}