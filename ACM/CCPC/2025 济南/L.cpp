#include<bits/stdc++.h>
using namespace std;
using ll =long long;

vector<ll>arr;
int n;
struct node{
    int l;int r;int father;
    int idx;
    ll mav;ll miv;
};

vector<node>shu;

struct tree {
   int n;
   vector<ll>tarr;

    tree (int n){
        this->n = n+1;
        tarr.resize(n+1);
    }

    int lowbit(int x) {
        return x&(-x);
    }

    void xiugai(int idx,ll num){
        
        while(idx < n){
            // cout <<"xiugai = "<<idx<<" "<<num<<"\n";
            tarr[idx] += num;
            idx += lowbit(idx);
        }
    }

    ll get(int l){
        ll sum=0;int idx = l;
        while(idx){
            // cout<<idx<<" "<<tarr[idx].l<<" "<<tarr[idx].r<<"\n";
            sum+=tarr[idx];
            // cout<<sum<<"\n";
            idx -= lowbit(idx);
        }
        return sum;
    }

    ll get(int l,int r){
        // cout<<get(r) <<" "<<get(l-1)<<"\n";
        return get(r) - get(l-1);
    }

};

void update(int idx , tree &ta){
    int idx1 = shu[idx].father;
    while(idx1!=0){
        int l = shu[idx1].l;int r = shu[idx1].r;
        ll old = shu[idx1].mav;
        shu[idx1].mav = max(shu[l].miv,shu[r].miv);
        shu[idx1].miv = min(shu[l].miv,shu[r].miv);
        if(idx1 - n > 0){
            ta.xiugai(idx1 - n , shu[idx1].mav - old);
        }
        idx1 = shu[idx1].father;
    }
}

void test()
{
    int q=0;
    cin>>n>>q;
    arr.resize(n+1);
    queue<node>q1;
    int idx=1;
    shu.resize((n<<2) + 2);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        node a;
        a.l=i;a.r=i;a.father=i;a.idx = i;
        a.mav = arr[i];a.miv = arr[i];
        shu[idx].father = i;
        shu[idx].mav = arr[i];
        shu[idx].miv = arr[i];
        q1.push(a);
        idx++;
    }
    
    tree ta ( n );
    ta.tarr.push_back(0);
    // cout<<"1\n";
    while(q1.size() > 1){
        auto a = q1.front();q1.pop();
        auto b = q1.front();q1.pop();
        // cout<<idx<<"\n";
        shu[idx].idx = idx;
        shu[idx].l = a.idx;
        shu[idx].r = b.idx;
        shu[a.idx].father = idx;
        shu[b.idx].father = idx;
        shu[idx].mav = max(a.miv,b.miv);
        // cout<<idx<<" = "<<shu[idx].mav<<"\n";
        shu[idx].miv = min(a.miv,b.miv);
        q1.push(shu[idx]);
        idx++;
    }

    for (int i = n + 1; i < idx; i++) {
        arr[i - n] = shu[i].mav;
    }
    for (int i = 1; i <= n - 1; i++) {
        ta.xiugai(i, arr[i]);
    }


    while(q--){
        char op;
        cin>>op;
        if(op == 'C'){
            int x=0;int y=0;
            cin>>x>>y;
           swap(shu[x].mav,shu[y].mav);
           swap(shu[x].miv,shu[y].miv);

           update(x,ta);
           update(y,ta);

        }else {
            int l=0;int r=0;
            cin>>l>>r;
            cout<<ta.get(l,r)<<"\n";
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}
