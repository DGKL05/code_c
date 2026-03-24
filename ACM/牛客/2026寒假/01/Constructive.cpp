#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        arr[i] = i+1;
    }
    int num1=1;int num2=0;
    for(int i=0;i<n;i++){
        num1*=arr[i];
        num2+=arr[i];
    }
    if(num1 != num2){
        cout<<"NO\n";
        return ;
    }
    cout<<"YES\n";
    for(auto x:arr) cout<<x<<" ";
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