#include<bits/stdc++.h>
using namespace std;
using ll =long long ;

void test(){
    
    int n,x;cin>>n>>x;
    int bits=__builtin_popcountll(x);
    if (n<=bits){cout<<x;return;}
    if ((n-bits)%2==0)cout<<x+n-bits;
    else{
        if (x>1){cout<<x+n-bits+1;return;}
        if (x==1){cout<<n+3;return;}
        else{
            if (n==1){cout<<-1;return;}
            else cout<<n+3;
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int t=0;
    cin>>t;
    while(t--) {
        test();
        cout<<"\n";
    }
    return 0;
}