#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(i) arr[i]+=arr[i-1];
    }
    for(int l=0;l<n-2;l++){
        for(int r=l+1;r<n-1;r++){
            vector<int>s1(3);
            s1[0]=arr[l];
            s1[1]=arr[n-1]-s1[0]-(arr[n-1]-arr[r]);
            s1[2]=arr[n-1]-arr[r];
            s1[0]%=3;
            s1[1]%=3;
            s1[2]%=3;
            if(s1[0]==s1[1] && s1[2]==s1[0]){
                cout<<l+1<<" "<<r+1<<"\n";
                return ;
            }
            bool fa = true;
            for(int i=0;i<3;i++){
                for(int j=i;j<n;j++){
                    if(i == j) continue;
                    if(s1[i] == s1[j]) {
                        fa = false;
                        break;
                    }
                }
            }
            if(fa){
                cout<<l+1<<" "<<r+1<<"\n";
                return ;
            }
        }
    }
    cout<<"0 0\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}
