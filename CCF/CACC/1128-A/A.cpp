#include<bits/stdc++.h>
using namespace std;
using ll =long long;

struct node{
    int pre;
    int idx;
    int net;
};

struct node_list{
    vector<node>arr;
    int sz;
    node_list (vector<int>&a){
        int n = a.size();
        arr.resize(n);
        this->sz = n;
        for(int i=0;i<n;i++){
            arr[i].idx = a[i];
            arr[i].pre = (i - 1 + n) % n;
            arr[i].net = (i + 1) % n; 
        }
    }

    int remove(int x){
        sz--;
        int prev = arr[x].pre;  
        int next = arr[x].net;  
        arr[prev].net = next;   
        arr[next].pre = prev;   
        return next;
    }

    int move(int x){
        return arr[x].net;
    }

    int get_size(){
        return sz;
    }

};

void test()
{
    int n=0;int m=0;
    cin>>n>>m;
    vector<int>a(n);
    for(int i=0;i<n;i++) a[i] = i;
    node_list li(a);
    int temp = 0;
    int num = 1;
    while(li.get_size() > 1){
        if(num == m){
            temp = li.remove(temp);
            num = 1;
        }else {
            num++;
            temp = li.move(temp);
        }
    }
    cout<<temp+1<<"\n";
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