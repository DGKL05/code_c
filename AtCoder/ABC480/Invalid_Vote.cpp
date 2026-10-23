#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void test(){
    int n=0;
    int m=0;
    cin>>n>>m;
    map<string,int>m1;
    vector<string>arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        m1[arr[i]] = 0;
    }
    vector<string>a1;
    for(int i=0;i<m;i++){
        string s1;
        cin>>s1;
        if(m1.find(s1) != m1.end()){
            m1[s1]++;
        }else a1.push_back(s1);
    }

    m = a1.size();
    for(int i=0;i<m;i++){
        int cnt=0;
        int pos=-1;
        for(int j=0;j<n;j++){
            if(arr[j].size() != a1[i].size()) continue;
            int n1 = arr[j].size();
            int ans=0;
            for(int k=0;k<n1;k++){
                if(arr[j][k] != a1[i][k]) ans++;
                if(ans >= 2) break;
            }
            if(ans == 1){
                cnt++;
                pos=j;
            }
        }
        if(cnt == 1){
            m1[arr[pos]]++;
        }
    }
    for(auto x:arr){
        cout<<m1[x]<<"\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    while(T--) test();
    return 0;
}