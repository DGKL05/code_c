#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n = 0;
    cin>>n;
    vector<vector<int>>arr(3);
    for(int i=1;i<=n;i++){
        arr[i%3].push_back(i);
    }
    vector<int>ans1,ans2;
    bool fa1 = true;
    bool fa2 = true;
    int mod = 1;
    int idx_2 = 0;
    int idx_1 = 1;
    int n1 = arr[1].size();
    int n2 = arr[2].size();
    ans1.push_back(1);
    for(int i=2;i<=n1+n2;i++){
        if(mod == 1){
            if(idx_1 < n1){
                ans1.push_back(arr[1][idx_1++]);
                mod = 2;
            }else {
                fa1 = false;
                break;
            }
        }else {
            if(idx_2 < n2){
                ans1.push_back(arr[2][idx_2++]);
                mod = 1;
            }else {
                fa1 = false;
                break;
            }
        }
    }
    
    if(fa1 == false) {
        cout<<"-1\n";
        return ;
    }
    int check = 0;
    for(auto x:arr[0]) {
        ans1.push_back(x);
    }
    for(auto x:ans1) {
        cout<<x<<" ";
        // check += x;
        // cout<<check%3 <<" ";
    }
    cout<<"\n";
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