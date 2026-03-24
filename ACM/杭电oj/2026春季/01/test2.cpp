#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    vector<int>nan,niu;
    vector<int>arr(n);
    vector<string>arrname(n);
    for(int i=0;i<n;i++){
        int a=0;string name;
        cin>>a>>name;
        arr[i] = a;
        arrname[i] = name;
        if(a == 0){
            niu.push_back(i);
        }else nan.push_back(i);
    }
    int nidx = nan.size()-1;
    int niuidx = niu.size()-1; 
    // for(auto x:niu){
    //     cout<<x<<" ";
    // }
    // cout<<"\n";
    // for(auto x:nan){
    //     cout<<x<<" ";
    // }
    // cout<<"\n";
    vector<bool>fa(n,false);
    for(int i=0;i<n;i++){
        if(fa[i]) continue;
        fa[i] = true;
        if(arr[i] == 0){
            while(fa[nan[nidx]]) nidx--;
            cout<<arrname[i]<<" "<<arrname[nan[nidx]]<<"\n";
            fa[nan[nidx]] = true;
        }else {
            while(fa[niu[niuidx]]) niuidx--;
            cout<<arrname[i]<<" "<<arrname[niu[niuidx]]<<"\n";
            fa[niu[niuidx]] = true;
        }
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