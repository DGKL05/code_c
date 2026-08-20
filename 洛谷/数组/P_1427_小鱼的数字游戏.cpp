#include<bits/stdc++.h>

using namespace std;

void test(){
    int num = -1;
    vector<int>ans;
    while(num != 0){
        cin>>num;
        if(num != 0) ans.push_back(num);
    }
    int n = ans.size();
    for(int i = n-1;i>=0;i--){
        cout<<ans[i]<<" ";
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