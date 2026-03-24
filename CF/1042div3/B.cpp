#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    bool fa=false;
    if(n==2){
        cout<<"-1 2\n";
        return ;
    }
    for(int i=0;i<n;i++){
        if(i%2==0) cout<<"-1 ";
        else {
            if(i==(n-1) && fa) cout<<"2 ";
            else {
                cout<<3<<" ";
                fa=true;
            }
        }
    }
    cout<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}
