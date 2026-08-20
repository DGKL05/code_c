#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void test(){
    int n=0;
    cin>>n;
    vector<int>arr(n);
    set<int>s1;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        s1.insert(arr[i]);
    }
    set<int>s2;
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(i == j) continue;
            if(s1.find(arr[i] + arr[j]) != s1.end() && s2.find(arr[i] + arr[j]) == s2.end()) {
                ans++;
                s2.insert(arr[i] + arr[j]);
            }
        }
    }
    cout<<ans<<'\n';
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