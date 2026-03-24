#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n;cin>>n;
    vector<int>ve(n+1);
    for(int i=1,j=2;i<n-1;i++,j++){
        ve[i]=(ve[i-1]+j)%n;
    }
    for(int i=0;i<n-1;i++){
        for(int j=(1-ve[i]+n)%n,co=0;co<n;j++,co++){
            j%=n;
            if(j==0) cout<<n<<" ";
            else cout<<j<<" ";
        }
        cout<<"\n";a
    }
    for(int i=1;i<=n;i++) cout<<i<<" ";
    cout<<'\n';
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}