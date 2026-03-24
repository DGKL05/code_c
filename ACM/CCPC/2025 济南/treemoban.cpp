#include<bits/stdc++.h>
using namespace std;
using ll =long long;

struct tree {
    int n;
    vector<int>arr;

    tree(int n){
        this->n = n+1;
        arr.resize(n+1);
    }

    int lowit(int x){
        return x & (-x);
    }

    void xiugai(int x,int p){
        while(x<=n){
            arr[x]+=p;
            x += lowit(x);
        }
    }

    int get(int l){
        int sum = 0;
        int x = l;
        while(x){
            sum+=arr[x];
            x -= lowit(x);
        }
        return sum;
    }

    int get(int l,int r){
        // cout<<"get : "<<get(r) <<" " << get(l-1)<<"\n";
        return get(r) - get(l-1);
    }

};

void test()
{
    int n=0;int m=0;
    cin>>n>>m;
    tree tarr(n);
    for(int i=0;i<n;i++){
        int num =0;
        cin>>num;
        tarr.xiugai(i+1,num);
    }

    for(int i=0;i<m;i++){
        int op = -1;
        cin>>op;
        if(op == 1){
            int idx=0;
            int p=0;
            cin>>idx>>p;
            tarr.xiugai(idx,p);
        }else {
            int l=0;int r=0;
            cin>>l>>r;
            cout<<tarr.get(l,r)<<"\n";
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