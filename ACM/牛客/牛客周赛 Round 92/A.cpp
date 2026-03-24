#include<bits/stdc++.h>
using namespace std;
using ll =long long;

int main()
{
    int n=6;
    vector<int>v1(n);
    for(int i=0;i<n;i++) v1[i]=i+1;
    do{
        vector<int>v2=v1;
        for(int k=0;k<n-1;k++){
            for(int i=0;i<v2.size()-1;i++){
                v2[i]=abs(v2[i]-v2[i+1]);
            }
            v2.resize(v2.size()-1);
        }
        if(v2[0]==n-2) {
            for(int x:v1) cout<<x<<' ';
            cout<<"\n";
        }
    }while(next_permutation(v1.begin(),v1.end()));
}