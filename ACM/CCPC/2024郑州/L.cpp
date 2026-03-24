#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    vector<vector<ll>>arr;
    arr.push_back ({0 ,1 ,4 ,5 ,16, 17 ,20 ,21});
    arr.push_back ({2 ,3 ,6 ,7 ,18 ,19, 22, 23});
    arr.push_back ({8 ,9 ,12 ,13 ,24 ,25 ,28 ,29});
    arr.push_back ({10, 11 ,14 ,15 ,26 ,27 ,30 ,31});
    ll l = 0 ;ll r = 0;
    cin>>l>>r;
    // cout<<l<<" "<<r<<"\n";
    // cout<<(l%(32))<<"\n";
    if(l<=31){
        if(r <= 31){
            cout<<l%8<<"\n";
        }else {
            cout<<l<<"\n";
        }
        return ;
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<8;j++){
            if(1LL*arr[i][j] == (1LL*l%(32)) ){
                cout<<arr[i][j]<<"\n";
                return ;
                // cout<<arr[i][j]<<" "<<arr[i][j] + r-l <<"\n";
                // cout<<(arr[i][j] + r-l  > l ? "da" : "xiao") << "\n";
            }
        }
    }
    // cout<<r-l<<"\n";  
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}