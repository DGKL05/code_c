#include<bits/stdc++.h>
using namespace std;
using ll =long long;
const int N=10005;
int n,q;
int a[N],b[N],p[N];
int dp[N][1010],qz[N];

void test()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>p[i]>>a[i]>>b[i],qz[i]=qz[i-1]+b[i];
    for(int i=0;i<=1000;i++) dp[n+1][i]=i;
    for(int i=n;i;i--) {
        for(int j=0;j<=1000;j++) {
            if(j<=p[i]&&j+a[i]<=1000) dp[i][j]=dp[i+1][j+a[i]];
            else dp[i][j]=dp[i+1][max(j-b[i],0)];
        }
    }
    cin>>q;int x;
    while(q--) {
        cin>>x;
        if(x>1000) {
            int l=1,r=n+1,res=n+1;
            while(l<=r) {
                int mid=(l+r)>>1;
                if(qz[mid]>=x-1000) {
                    res=mid;
                    r=mid-1;
                }else l=mid+1;
            }//printf("%d ",x-qz[res]);
            if(res<=n) printf("%d\n",dp[res+1][x-qz[res]]);
            else printf("%d\n",x-qz[n]);
        }else printf("%d\n",dp[1][x]);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}