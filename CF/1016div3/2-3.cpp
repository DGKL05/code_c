#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int sum[N];
//00:00:00
int main() {
    int n=0;
    cin>>n;
    for(int i=0;i<n;i++){
        string s1;string s2;
        cin>>s1>>s2;
        int l=0;int r=0; 
        int a=stoi(s1.substr(0,2));
        if(a) l+=(a-1)*60*60;
        a=stoi(s1.substr(3,2));
        l+=a*60;
        l+=stoi(s1.substr(6,2)); 

        a=stoi(s2.substr(0,2));
        if(a) r+=(a-1)*60*60;
        a=stoi(s2.substr(3,2));
        r+=a*60;
        r+=stoi(s2.substr(6,2));  
        //差分处理
        sum[l]++;sum[r+1]--;
    }
    for(int i=1;i<N;i++) sum[i]=sum[i-1]+sum[i];
    int num=0;
    for(int i=0;i<N;i++){
        num=max(num,sum[i]);
    }
    cout<<num<<"\n";
    return 0;
}