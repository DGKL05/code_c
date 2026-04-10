#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void test(){
    int n=0;int m=0;
    cin>>n>>m;
    vector<bool>fa(n,false);
    vector<vector<int>>arr(n);
    map<ll,int>m1;
    for(int i=0;i<n;i++){
        ll num = 0;
        cin>>num;
        m1[num] = i;
    }
    for(int i=0;i<m;i++){
        int a=0;int b=0;
        cin>>a>>b;
        a--;
        b--;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    for(int i=0;i<n;i++){
        sort(arr[i].begin() , arr[i].end());
    }
    // cout<<"=======================\n";
    // int idx1=0;
    // for(auto x:arr){
    //     cout<<idx1++<<" -> ";
    //     for(auto x1:x){
    //         cout<<x1<<" ";
    //     }
    //     cout<<"\n";
    // }
    auto it = m1.end();
    it--;
    while(it != m1.begin()){
        int idx = it->second;
        if(fa[idx]) {
            it--;
            continue;
        }
        for(auto x:arr[idx]){
            if(!fa[x]){
                fa[x] = true;
                fa[idx] = true;
                // cout<<idx<<" "<<x<<"\n";
                if(idx == 0) {
                    cout<<x+1<<"\n";
                    return ;
                }
                if(x == 0){
                    cout<<idx+1<<"\n";
                    return ;
                }
                break;
            }
        }
        it--;
    }
    // for(int i=1;i<n;i++){
    //     if(fa[i]) cout<<i+1<<"\n";
    // }
    int idx = it->second;
    for(auto x:arr[idx]){
        if(!fa[x] && !fa[idx]){
            if(x == 0){
                cout<<idx+1<<"\n";
                return ;
            }
            if(idx == 0){
                cout<<x+1<<"\n";
                return ;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    // cin>>T;
    while(T--) test();
    return 0;
}