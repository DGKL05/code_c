#include<bits/stdc++.h>
using namespace std;
using ll =long long;

// struct TreeArr{
//     vector<int>arr;
//     int n;
//     TreeArr (int n){
//         arr.resize(n+1);
//         n = n;
//         for(int i=0;i<=n;i++){
//             arr[i] = 1;
//         }
//         int lowite(int x){
//             return x & (-x);
//         }
//         void update(int idx , int num){
//             while(idx <= n){
//                 arr[idx] += num;
//                 idx += lowite(idx);
//             }            
//         }
//         int get(int idx){
//             int ans=0;
//             while(idx > 0){
//                 ans+=arr[idx];
//                 idx -= lowite(idx);
//             }
//             return ans;
//         }
//     }
// };

void test()
{
    int n=0;int m=0;ll h=0;
    cin>>n>>m>>h;
    // vector<ll>arr(n,0);
    vector<ll>arr(n+1 , 0);
    vector<ll>barr(n+1 , 0);
    for(int i=0;i<n;i++){
        cin>>arr[i+1];
        barr[i+1] = arr[i+1];
    }
    // TreeArr tarr(n);
    int temp=1;
    vector<int>idx_arr;
    while(m--){
        int idx = 0;
        ll c=0;
        cin>>idx>>c;
        ll num = 0;
        num = barr[idx];
        if(num+c > h){
            int n1 = idx_arr.size();
            for(int i=0;i<n1;i++){
                barr[idx_arr[i]] = arr[idx_arr[i]];
            }
            idx_arr.clear();
            continue;
        }
        barr[idx] += c;
        idx_arr.push_back(idx);
    }
    for(int i=1;i<=n;i++){
        cout<<barr[i]<<" ";
    }
    cout<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}