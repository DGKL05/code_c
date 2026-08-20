#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void test(){
    int a=0;int b=0;int c=0;
    cin>>a>>b>>c;
    map<int,int>m1;
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            for(int k=1;k<=c;k++){
                m1[i+j+k]++;
            }
        }
    }
    int ans = 0;
    int ans1=0;
    for(auto [l,r] : m1){
        if(r > ans) {
            ans1 = l;
            ans = r;
        }
    }
    cout<<ans1<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin>>T;
    while(T--) test();
    return 0;
}