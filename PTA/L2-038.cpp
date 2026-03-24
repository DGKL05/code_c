#include<bits/stdc++.h>
using namespace std;
using ll =long long;
int n;
vector<vector<int>>arr;
vector<int>ans;
int k;

void dfs(int idx,int num,vector<int>&temp){
    // cout<<idx<<" "<<num<<"\n";
    if(num > k){
        k = num;
        ans = temp;
    }
    for(auto x : arr[idx]){
        temp.push_back(x);
        dfs(x , ++num , temp);
        if(num > k){
            k = num;
            ans = temp;
        }
        --num;
        temp.pop_back();
    }
}

void test()
{
    cin>>n;
    if(n == 1){
        cout<<"1\n0";
        return ;
    }
    arr.resize(n);
    vector<int>du(n);
    for(int i=0;i<n;i++){
        int k=0;
        cin>>k;
        for(int j=0;j<k;j++){
            int num = 0;
            cin>>num;
            arr[i].push_back(num);
            du[num]++;
        }
    }
    for(int i=0;i<n;i++){
        sort(arr[i].begin(),arr[i].end());
    }
    int idx=0;
    while(du[idx]) ++idx;
    k=1;
    vector<int>ans1;
    ans1.push_back(idx);
    dfs(idx , 1 , ans1);
    cout<<ans.size()<<"\n";
    int n1=ans.size();
    for(int i=0;i<n1;i++){
        cout<<ans[i];
        if(i != n1-1) cout<<" ";
    }
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