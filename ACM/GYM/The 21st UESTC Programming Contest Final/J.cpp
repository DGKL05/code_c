#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    // cout<<"1--1\n";
    cin>>n;
    vector<int>v1(n+1,0);
    for(int i=1;i<=n;i++){
        int a,b;
        cin>>a>>b;
        v1[b]=a;
    }
    // for(int x:v1) cout<<x<<" ";
    queue<int>q1;
    stack<int>check_1;
    queue<int>check_01;
    vector<vector<int>>v2(n);
    int j=-1;
    for(int i=1;i<=n;i++){
        if(v1[i]==1) {
            q1.push(i);
            check_1.push(i);
            j++;
        }
        if(v1[i]==-1){
            check_01.push(i);
            if(j==-1) j++;
            v2[j].push_back(i);
        }
    }
    for(int i=1;i<=n;i++){
        if(v1[i]==1){
            if(check_01.size()==0){
                cout<<"-1\n";
                return ;
            }
            if(check_01.front()<i){
                i--;
                check_01.pop();
            }
            
        }
    }
    for(int i=n;i>=1;i--){
        if(v1[i]==-1){
            if(check_1.size()==0){
                cout<<"-1\n";
                return ;
            }
            if(check_1.top()>i){
                i++;
                check_1.pop();
            }
        }
    }
    int index=0;int num=0;
    for(int i=1;i<=n;i++){
        if(v1[i]==0) cout<<i<<' ';
        else if(v1[i]==1){
            cout<<v2[index][num]<<' ';
            num++;
        }else if(v1[i]==-1){
            if(num!=v2[index].size()) {
                cout<<v2[index][num]<<' ';
                num++;
            }else{
                num=0;
                index++;
                int a=q1.front();
                q1.pop();
                cout<<a<<' ';
            }
        }
    }
    cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test();
    return 0;
}