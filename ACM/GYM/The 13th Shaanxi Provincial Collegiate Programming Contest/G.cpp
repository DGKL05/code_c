#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5+5;
int q_min[N],q_max[N],h_min[N],h_max[N];
int a[N];
void test()
{
    int n=0;ll num=0;
    cin >> n ;
    for(int i = 1 ; i <= n ; i ++)
        cin >> a[i] ;
    if(n <= 2) {
        cout << n << "\n" ;
        return;
    }
    int res = 4 ;
    int mx = 0 , mn = 1e9 ;
    for(int i = 1 ; i <= n ; i ++)
        mx = max(mx , a[i]) , mn = min(mn , a[i]) ;
    if(mx == a[1] || mx == a[n]) res -- ;
    if(mn == a[1] || mn == a[n]) res -- ;
    cout << res << "\n" ;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T:
    while(T--) test();
    return 0;
}