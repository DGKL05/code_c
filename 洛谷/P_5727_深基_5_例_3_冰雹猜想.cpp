#include<bits/stdc++.h>

using namespace std;

void test(){
    int n=0;
    cin>>n;
    vector<int>arr;
    arr.push_back(n);
    while(n != 1){
        if(n & 1) n = n*3+1;
        else n/=2;
        arr.push_back(n);
    }
    // arr.push_back(1);
    int n1 = arr.size();
    for(int i = n1 - 1;i>=0;i--) cout<<arr[i]<<" ";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin>>T;
    while(T--) test();
    return 0;
}