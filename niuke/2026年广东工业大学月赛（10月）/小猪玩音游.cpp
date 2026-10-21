#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void test()
{
    int n,m;
    cin>>n>>m;
    vector<double>d(n+1),best(n+1,0);
    for(int i=1;i<=n;i++) {
        cin>>d[i];   
    }
    for(int i=0;i<m;i++){
        int x;
        double a;
        cin>>x>>a;
        if(a<97.50) continue;
        double s=d[x]+2.15*(a-97.50)/3.40;
        best[x]=max(best[x],s);
    }
    sort(best.begin()+1,best.end(),greater<double>());
    double ans=0;
    for(int i=1;i<=min(n,30);i++){
        ans+=best[i];
    }

    cout<<fixed<<setprecision(10)<<ans/30.0<<"\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T=1;
    while(T--) test();
    return 0;
}
