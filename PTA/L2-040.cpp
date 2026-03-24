#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;int m=0;
    cin>>n>>m;
    vector<vector<int>>arr(n);
    vector<int>jump(100);
    for(int i=0;i<n;i++){
        int k=0;
        cin>>k;
        // cout<<k<<"\n";
        for(int j=0;j<k;j++){
            int num=0;
            cin>>num;
            --num;
            arr[i].push_back(num);
        }
    }
    int idx = 0;
    while(m--){
        int op = 0;int num=0;
        cin>>op>>num;
        --num;
        if(op == 0){
            idx = arr[idx][num];
        }else if(op == 1){
            cout<<idx+1<<"\n";
            jump[num] = idx;
        }else {
            idx = jump[num];
        }
    }
    cout<<idx+1<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}