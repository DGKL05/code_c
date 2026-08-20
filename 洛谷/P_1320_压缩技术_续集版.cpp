#include<bits/stdc++.h>

using namespace std;

void test(){
    string s1;
    vector<int>arr;
    int ans=0;
    string a1;
    while(getline(cin,s1)){
        // s1+="*";
        // cout<<s1<<"\n";
        a1+=s1;
    }
    a1+="*";
    // cout<<a1<<"\n";
    int n = a1.size();
    int temp=1;
    for(int i=0;i<n-1;i++){
        if(a1[i] != a1[i+1]){
            arr.push_back(temp);
            ans+=temp;
            temp = 1;
        }else temp++;
    }
    cout<<sqrt(ans)<<" ";
    if(a1[0] == '1') cout<<"0 ";
    for(auto x:arr) cout<<x<<" ";
    cout<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin>>T;
    while(T--) test();
    return 0;
}