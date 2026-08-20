#include<bits/stdc++.h>

using namespace std;

void test(){
    int n = 0;
    cin >> n;
    int ans = 0;
    vector<int>arr;
    int idx = 0;
    while(ans < n*n){
        int num = 0;
        cin>>num;
        for(int i=0;i<num;i++) arr.push_back(idx);
        if(idx) idx = 0;
        else idx = 1;
        ans+=num;
    }
    idx=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[idx++];
        }
        cout<<"\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin>>T;
    while(T--) test();
    return 0;
}