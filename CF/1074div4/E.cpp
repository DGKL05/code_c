#include<bits/stdc++.h>
using namespace std;
using ll =long long;
void test()
{
    int n=0;int m=0;int k=0;
    cin>>n>>m>>k;
    vector<int>a(n),b(m);
    vector<bool>fa(n,false);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    map<int,vector<int>>m1;
    sort(a.begin() , a.end());
    sort(b.begin() , b.end());
    // for(auto x:a){
    //     cout<<x<<" ";
    // }cout<<"\n";
    // for(auto x:b){
    //     cout<<x<<" ";
    // }cout<<"\n";
    int ans = n;
    int j = 0;
    for(int i=0;i<n;i++){
        while(b[j] < a[i] && j<m){
            j++;
        }
        // cout<<i<<" "<<j<<"\n";
        if(j >= m) break;
        if(b[j] < a[i]) break;
        if(b[j] - a[i] == 0) {
            ans--;
            continue;
        }
        int num = b[j] -a[i];
        // cout<<num<<"\n";
        if(m1.find(num) == m1.end()){
            vector<int>v1;
            v1.push_back(i);
            m1[num] = v1;
        }else {
            m1[num].push_back(i);
        }
    }
    // for(auto [l , r] : m1){
    //     cout<<l<<" ";
    // }
    j = m-1;
    for(int i = n-1;i>=0;i--){
        while(b[j] > a[i] && j>=0){
            j--;
        }
        // cout<<i<<" "<<j<<"\n";
        if(j < 0) break;
        if(b[j] > a[i]) break;
        if(b[j] - a[i] == 0) {
            ans--;
            continue;
        }
        int num = b[j] -a[i];
        // cout<<num<<"\n";
        // m1[num].push_back(i);
        if(m1.find(num) == m1.end()){
            vector<int>v1;
            v1.push_back(i);
            m1[num] = v1;
        }
        else {
            m1[num].push_back(i);
        }
    }

    int ind = 0;
    while(k--){
        char a ;
        cin>>a;
        if(a == 'L') ind--;
        else ind++;
        if(m1.find(ind) != m1.end()){
            for(auto x:m1[ind]){
                if(fa[x]) continue;
                fa[x] = true;
                ans--;
            }
            m1[ind].clear();
        }
        cout<<ans<<" ";
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