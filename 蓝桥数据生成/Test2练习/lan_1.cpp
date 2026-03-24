#include<bits/stdc++.h>
using namespace std;
using ll =long long;
vector<int>v1;
bool check(int num)
{
    // int n=num;
    // cout<<num<<"\n";
    if(num==1) return true;
    if((num&(num-1))==0) return true;

    return false;
}
int main()
{
    //cout<<kuai_pow(9,9,100000000000);
    int n=0;
    cin>>n;
    v1.resize(n);
    for(int i=0;i<n;i++) cin>>v1[i];
    int ans=0;
    for(int i=0;i<n;i++){
        if(!check(v1[i])) ans++;
    }
    cout<<ans<<"\n";
    return 0;
}