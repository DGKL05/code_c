#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

int f(int x,int y,int x1,int y1){
    return max(abs(x-x1),abs(y-y1));;
}

void test(){
    int n=0;int m=0;
    cin>>n>>m;
    vector<int>arr(n);
    for(int i=n-1,k=1;i>=0;i--,k++){
        arr[i] = k;
    }
    int ans = 0;
    for(int i=0;i<m;i++){
        int x=0;int y=0;
        cin>>x>>y;
        ans += arr[(f(x,y,n,n))];
    }
    cout<<ans<<"\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T = 1;
    // cin>>T;
    while(T--) test();
    return 0;
}