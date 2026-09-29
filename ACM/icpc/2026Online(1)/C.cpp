#include<bits/stdc++.h>

using namespace std;
using ll = long long;

struct node{
    ll l;
    ll r;
};

void test(){
    int n = 0;
    int m = 0;
    cin>>n>>m;
    set<ll>s1;
    for(int i=0;i<n;i++){
        s1.insert(i+1);
    }
    vector<ll>arr(n);
    vector<vector<ll>>a(m);
    vector<node>b(m);
    for(int i=0;i<m;i++){
        int l=0;int r=0;
        cin>>l>>r;
        l--;r--;
        b[i].l = l;
        b[i].r = r;
        for(int j=l;j<=r;j++){
            int num=0;
            cin>>num;
            a[i].push_back(num);
        }
    }
    // for(int i=0;i<m;i++){
    //     for(auto x:a[i]){
    //         cout<<x<<" ";
    //     }
    //     cout<<"\n";
    // }
    for(int i=0;i<m;i++){
        int l=b[i].l;int r=b[i].r;
        int idx=0;
        for(int j=l;j<=r;j++,idx++){
            // cout<<j<<" "<<a[i][idx]<<"\n";
            if(arr[j] == 0){
                arr[j] = a[i][idx];
                if(s1.find(a[i][idx]) != s1.end()) s1.erase(a[i][idx]);
                else {
                    cout<<"-1\n";
                    return ;
                }
            }else {
                if(arr[j] != a[i][idx]){
                    cout<<"-1\n";
                    return ;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        if(arr[i] == 0){
            arr[i] = *(s1.begin());
            s1.erase(s1.begin());
        }
    }
    for(auto x:arr) cout<<x<<" ";
    cout<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin>>T;
    while(T --) test();
    return 0;
}