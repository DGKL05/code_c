#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void test(){
    int n=0;
    cin>>n;
    set<int>s1;
    for(int i=0;i<7;i++){
        int num = 0;
        cin>>num;
        s1.insert(num);
    }
    vector<int>arr(7);
    for(int i=0;i<n;i++){
        int ans=0;
        for(int j=0;j<7;j++){
            int num = 0;
            cin>>num;
            if(s1.find(num) != s1.end()) ans++;
        }
        // cout<<7-ans<<" ";
        arr[7-ans]++;
    }
    for(int i=0;i<7;i++) {
        cout<<arr[i]<<" ";
    }
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