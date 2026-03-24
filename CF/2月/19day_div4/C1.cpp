#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;int m=1;
    cin>>n>>m;
    vector<int>v1(n);
    vector<int>check(n,0);
    for(int i=0;i<n;i++){
        cin>>v1[i];
    }
    int b=0;
    cin>>b;
    if(n==1){
        cout<<"Yes\n";
        return ;
    }
    bool t=false;
    for(int i=0;i<n;i++){
        if(v1[i]<=v1[i+1]) t=true;
    }
    if(!t){
        cout<<"Yes\n";
        return ;
    }
    for(int i=0;i<n-1;i++){
        if(v1[i]>v1[i+1]){
            bool fa=false;
            if(b-v1[i]<=v1[i+1]){
                int temp=v1[i];
                v1[i]=b-v1[i];
                fa=true;
                check[i]++;
                if(i!=0){
                    if(v1[i-1]>v1[i]) {
                        v1[i]=temp;
                        fa=false;
                        check[i]--;
                    }
                }
            }
            if(fa) continue;
            if(v1[i]<=b-v1[i+1]){
                int temp=v1[i];
                v1[i+1]=b-v1[i+1];
                fa=true;
                check[i+1]++;
            }
            if(!fa){
                cout<<"No\n";
                return ;
            }
        }
    }
    for(int x:check){
        if(x>=2){
            cout<<"No\n";
            return ;
        }
    }
    cout<<"Yes\n";
}

int main()
{
    int t=0;
    cin>>t;
    while(t--){
        test();
    }
}