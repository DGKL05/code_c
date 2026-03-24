#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void test()
{
    int n=0;ll num=0;
    cin>>n;
    if(n%2==0){
        int index=0;int k=0;
        for(int i=0;i<n;i++){
            int ans=0;
            if(k==2){
                index+=2;
                k=0;
            }
            k++;
            for(int j=index;j<n;j++){
                // cout<<(i-1)*n+j<<' ';
                if(ans<2){
                    num+=i*n+(j+1);
                    // cout<<i*n+(j+1)<<"\n";
                    ans++;
                }else{
                    break;
                }
            }
        }
    }else{
        int index=0;int k=0;
        for(int i=0;i<n-3;i++){
            int ans=0;
            if(k==2){
                index+=2;
                k=0;
            }
            k++;
            for(int j=index;j<n-3;j++){
                // cout<<(i-1)*n+j<<' ';
                if(ans<2){
                    num+=i*n+(j+1);
                    // cout<<i*n+(j+1)<<"\n";
                    ans++;
                }else{
                    break;
                }
            }
        }
        int i=n-3;int j=n-3;
        num+=i*n+(j+1);
        j++;
        num+=i*n+(j+1);
        i++;
        num+=i*n+(j+1);
        j++;
        num+=i*n+(j+1);
        j=n-3;i++;
        num+=i*n+(j+1);
        j=n-1;
        num+=i*n+(j+1);
    }
    cout<<num<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T:
    while(T--) test();
    return 0;
}