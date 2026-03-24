#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5+5;

ll arr[N];ll val[N];
void test()
{
    int n=0;ll num=0;
    cin >> n ;
    vector<int> p[n + 3] ;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i=1;i<=n;i++){
        cin>>val[i];
    }
    int u = 1 ;
    for(int i = 2 ; i <= n ; i ++)
        if(arr[i] == arr[i - 1]) u ++ ;
        else {
            p[arr[i - 1]].push_back(u) ;
            u = 1 ;
        }
    p[arr[n]].push_back(u) ;
    for(int i=1;i<=n;i++){
        int l=0;int r=n;bool fa=false;
        for(int j=1;j<=n;j++){
            if(arr[j]!=i) {l=j;fa=true;break;}
        }
        for(int j=n;j>=1;j--){
            if(arr[j]!=i) {r=j;fa=true;break;}
        }
        int ans = val[i] + r - l + 1 ;
        if(p[i].size()) {
            sort(p[i].begin() , p[i].end()) ;
            for(int j = p[i].size() - 1 ; j >= 0 ; j --) {
                if(p[i][j] > val[i]) ans -= p[i][j] - val[i] ;
                else break;
            }
        }
        cout << ans << " " ;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T:
    while(T--) test();
    return 0;
}