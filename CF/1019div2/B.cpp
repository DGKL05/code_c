#include <bits/stdc++.h>
using namespace std;

void test()
{
    int n=0;
    cin>>n;
    string s1;
    cin>>s1;
    s1='0'+s1;
    int cnt=0;
    // if(s1[0]=='1') cnt++;
    for(int i=1;i<=n;i++){
        if(s1[i-1]!=s1[i]) cnt++;
    }
    if(cnt==0) {
        if(s1[1]=='1') {
            cout<<n+1<<"\n";
            return ;
        }else{
            cout<<n<<"\n";
            return ;
        }
    }
    if(cnt>=3){
        cnt-=2;
    }
    else {
        if(cnt==2){
            cnt--;
        }
    }
    cout<<n+cnt<<"\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) test();
    return 0;
}