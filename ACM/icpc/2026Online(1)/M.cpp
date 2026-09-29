#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void test(){
    int n = 0;
    int m = 0;
    cin>>n>>m;
    map<string,int>m1;
    for(int i=0;i<n;i++){
        string s1;
        cin>>s1;
        m1[s1]++;
    }
    for(int i=0;i<m;i++){
        string s1;
        cin>>s1;
        if(m1.find(s1) == m1.end()){
            cout<<"WRONG\n";
        }else {
            if(m1[s1] == 1){
                cout<<"OK\n";
                m1[s1]++;
            }else cout<<"REPEAT\n";
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin>>T;
    while(T --) test();
    return 0;
}