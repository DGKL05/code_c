#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void test(){
    int n=0;int m=0;int k=0;
    cin>>n>>k>>m;
    int ans=0;
    string s1;
    cin>>s1;
    for(int i=0;i<m;i++){
        int op = (s1[i] - '0');
        // cin>>op;
        // cout<<op<<"\n";
        if(op == 0){
            if(k != n) k++;
        }else {
            if(k == 0) ans++;
            else k--;
        }
    }
    cout<<ans<<"\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T = 1;
    cin>>T;
    while(T--) test();
    return 0;
}