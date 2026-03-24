#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void test()
{
    int n=0;
    cin>>n;
    int a=0;int b=0;
    vector<int>A(n);
    int idx=-1;
    int ans=0;
    for(int i=0;i<n;i++){
        cin>>A[i];
        ans ^= A[i];
    }
    
    vector<int>M(n);
    for(int i=0;i<n;i++){
        int num=0;
        cin>>num;
        M[i] = num;
        ans ^= M[i];
        if(num!=A[i]){
            idx = i;
        }
    }
    if(!ans){
        cout<<"Tie\n";
    }else if((idx & 1) == 0){
        cout<<"Ajisai\n";
    }else cout<<"Mai\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T=1;
    cin>>T;
    while(T--) test();
    return 0;
}