/*
    [i][n] = [0][i] 
    [i][n-1] = [1][i] 
    [i][k++] = [j++][i] 
    [i][0] = [n][i] 
*/
#include<bits/stdc++.h>

using namespace std;
int n=0;
vector<string> move1(vector<string> &a){
    vector<string>s1 = a;
    for(int j=0;j<n;j++){
        for(int i=0;i<n;i++){
            s1[i][n-1-j] = a[j][i];
            // cout<<i<<" "<<n-1-j<<" "<<j<<" "<<i<<"\n";
        }
    }
    return s1;
}

vector<string> move2(vector<string> &a){
    vector<string>s1 = a;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n / 2; j++){
            swap(s1[i][j], s1[i][n - 1 - j]);
        }
    }
    return s1;
}


bool check(vector<string> &a,vector<string>b){
    for(int i=0;i<n;i++){
        if(a[i] == b[i]) continue;
        else return false;
    }
    return true;
}

void test(){
    cin>>n;
    vector<string>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<string>temp = arr;
    vector<string>ans(n);
    for(int i=0;i<n;i++){
        cin>>ans[i];
    }
    
    for(int i=0;i<3;i++){
        temp = move1(temp);
        if(check(temp,ans)){
            cout<<i+1<<"\n";
            return ;
        }
    }
    temp = arr;
    temp = move2(temp);
    if(check(ans,temp)){
        cout<<"4\n";
        return ;
    }
    for(int i=0;i<3;i++){
        temp = move1(temp);
        if(check(temp,ans)){
            cout<<"5\n";
            return ;
        }
    }
    if(check(ans,arr)){
        cout<<"6\n";
        return ;
    }
    cout<<"7\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin>>T;
    while(T--) test();
    return 0;
}