#include<bits/stdc++.h>
using namespace std;
int main()
{
    std::ios_base::sync_with_stdio(false);
    int n=0;
    cin>>n;int num=0;
    int *a=new int[n];
    for(int i=0;i<n;i++){
        cin>>num;
        a[i]=num;
    } 
    cin>>num;
    int* i = lower_bound(a, a+n, num);
    cout<<i-a+1<<endl; 
    return 0;
}