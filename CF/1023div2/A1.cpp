#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    vector<int>v1(n);//前i个数的GCD
    vector<int>v2(n);
    for(int i=0;i<n;i++){
        cin>>v2[i];
    }
    if(n==2){
        if(v2[0]!=v2[1]){
            cout<<"YES\n1 2\n";
        }else cout<<"NO\n";
        return ;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(__gcd(v2[i],v2[j])==1){
                if(v2[i]==v2[j]&&v2[i]==1) continue;
                int index = v2[i] < v2[j] ? i : j;
                // cout<<i<<' '<<j<<"\n";
                cout<<"YES\n";
                for(int k=0;k<n;k++){
                    if(k!=i&&k!=j||k == index) cout<<"1 ";
                    else cout<<"2 ";
                }
                cout<<"\n";
                return ;
            }
        }
    }
    cout<<"NO\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int t=0;
    cin>>t;
    while(t--) test();
    return 0;
}