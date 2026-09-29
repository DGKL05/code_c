#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using i128 = __int128_t;

struct node{
    ll w,c;
};

void print128(i128 x){
    if(x == 0){
        cout<<0<<"\n";
        return;
    }

    string s;

    while(x){
        s.push_back('0'+x%10);
        x/=10;
    }

    reverse(s.begin(),s.end());

    cout<<s<<"\n";
}

void test(){
    ll n;
    int m;

    cin>>n>>m;

    vector<pair<ll,ll>>e;

    for(int i=0;i<m;i++){
        ll l,r;
        cin>>l>>r;

        e.push_back({l,1});
        e.push_back({r+1,-1});
    }

    if(n == 1){
        cout<<m<<"\n";
        return;
    }

    sort(e.begin(),e.end());

    vector<node>a;

    ll pos = 1;
    ll cnt = 0;
    int id = 0;

    while(pos <= n){

        while(id < e.size() && e[id].first == pos){
            cnt += e[id].second;
            id++;
        }

        // 当前 cnt 能保持到哪里
        ll nxt = n;

        if(id < e.size()){
            nxt = min(n,e[id].first-1);
        }

        ll r = nxt;

        // 如果 cnt != 0，还需要同时考虑 floor(n/k) 的分块
        if(cnt != 0){
            ll q = n/pos;
            r = min(r,n/q);
        }

        ll q = n/pos;

        // [pos,r] 内：
        // 被启动次数都是 cnt
        // floor(n/k) 都是 q
        // 所以 Huffman 权值都是 cnt*q
        a.push_back({
            cnt*q,
            r-pos+1
        });

        pos = r+1;
    }

    // Huffman 需要按照权值排序
    sort(a.begin(),a.end(),[](node A,node B){
        return A.w < B.w;
    });

    // 把相同权值合并
    vector<node>p;

    for(auto [w,c]:a){
        if(!p.empty() && p.back().w == w){
            p.back().c += c;
        }else{
            p.push_back({w,c});
        }
    }

    /*
        p：原始 Huffman 权值
        q：Huffman 合并产生的权值
    */

    deque<node>q;

    int now = 0;

    // 向 q 中加入一组节点
    auto pushq = [&](ll w,ll c){

        if(c == 0) return;

        if(!q.empty() && q.back().w == w){
            q.back().c += c;
        }else{
            q.push_back({w,c});
        }
    };

    // 取出当前最小权值的整组节点
    auto get_group = [&]() -> node{

        if(now < p.size() && !q.empty()){

            if(p[now].w < q.front().w){
                return p[now++];
            }

            if(p[now].w > q.front().w){
                node res = q.front();
                q.pop_front();
                return res;
            }

            node res = {
                p[now].w,
                p[now].c+q.front().c
            };

            now++;
            q.pop_front();

            return res;
        }

        if(now < p.size()){
            return p[now++];
        }

        node res = q.front();
        q.pop_front();

        return res;
    };

    // 只取当前最小的一个节点
    auto get_one = [&]() -> ll{

        if(now < p.size() &&
           (q.empty() || p[now].w <= q.front().w)){

            ll w = p[now].w;

            p[now].c--;

            if(p[now].c == 0){
                now++;
            }

            return w;
        }

        ll w = q.front().w;

        q.front().c--;

        if(q.front().c == 0){
            q.pop_front();
        }

        return w;
    };

    ll tot = n;

    i128 ans = 0;

    while(tot > 1){

        node cur = get_group();

        ll w = cur.w;
        ll c = cur.c;

        /*
            c 个 w 两两合并
        */

        ll num = c/2;

        if(num){

            ans += (i128)(2*w)*num;

            pushq(2*w,num);

            // 每进行一次合并，总节点数减少 1
            tot -= num;
        }

        /*
            如果有一个 w 剩下来
            和当前次小值合并
        */

        if(c&1){

            ll y = get_one();

            ll z = w+y;

            ans += z;

            pushq(z,1);

            tot--;
        }
    }

    print128(ans);
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