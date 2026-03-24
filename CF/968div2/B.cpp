#include<bits/stdc++.h>
using namespace std;
using ll =long long;
const int l =1e7;
void test()
{
    int n=0;
    cin>>n;
    vector<int>v1(n);
    for(int i=0;i<n;i++){
        cin>>v1[i];
    }
    for(int i=1;i<n;i++) cout<<v1[i]<<' ';
    cout<<v1[0];
    cout<<"\n";
}

int main()
{
    int t=1;
    cin>>t;
    while(t--) test();
    return 0;
}