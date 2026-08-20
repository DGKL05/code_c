#include<bits/stdc++.h>

using namespace std;
using ll  =long long;

struct node{
    int a=0;
    int b=0;
    int c=0;
    int num=0;
};

bool check(node &a,node &b){
    if(abs(a.a - b.a)<=5 && abs(a.b - b.b)<=5 && abs(a.c - b.c)<=5 && abs(a.num - b.num)<=10 ) return true;
    return false;
}

void test(){
    int n = 0;
    cin>>n;
    vector<node>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i].a>>arr[i].b>>arr[i].c;
        arr[i].num = (arr[i].a+arr[i].b+arr[i].c);
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(i == j) continue;
            if(check(arr[i],arr[j])) ans++;
        }
    }
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin>>T;
    while(T--) test();
    return 0;
}