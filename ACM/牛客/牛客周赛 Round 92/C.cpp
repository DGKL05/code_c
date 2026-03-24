#include<bits/stdc++.h>
using namespace std;
using ll =long long;

int main()
{
    int n=6;
    cin>>n;
    if(n<=2){
        cout<<"-1\n";
        return 0;
    }
    if(n==3){
        cout<<"1 3 2\n";
        return 0;
    }
    cout<<n<<" ";
    for(int i=1;i<n;i++) cout<<i<<" ";
    return 0;
}