#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    ll w=0;ll h=0;ll d=0;
    cin>>w>>h>>d;
    ll n=0;
    cin>>n;
    if(n == 1){
        cout<<"0 0 0\n";
        return ;
    }
    vector<vector<ll>>arr(3);
    ll temp = w;
    int idx=0;
    for(int i=2;1LL*i*i<=temp;i++){
        if(temp%i == 0){
            arr[idx].push_back(i);
            arr[idx].push_back(temp/i);
        } 
    }
    temp = h;
    idx = 1;
    for(int i=2;1LL*i*i<=temp;i++){
        if(temp%i == 0){
            arr[idx].push_back(i);
            arr[idx].push_back(temp/i);
        } 
    }

    temp = d;
    idx = 2;
    for(int i=2;1LL*i*i<=temp;i++){
        if(temp%i == 0){
            arr[idx].push_back(i);
            arr[idx].push_back(temp/i);
        } 
    }

    for(int i = 0;i<arr[0].size();i++){
        for(int j=0;j<arr[1].size();j++){
            for(int k=0;k<arr[2].size();k++){
                if(arr[0][i] * arr[1][j] * arr[k][2] == n){
                    cout<<(w / arr[0][i]) - 1<<" "<<(h / arr[1][j]) - 1<<" "<<(d / arr[2][k]) - 1<<"\n";
                    return ;
                }
            }
        }
    }
    cout<<"-1\n";
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