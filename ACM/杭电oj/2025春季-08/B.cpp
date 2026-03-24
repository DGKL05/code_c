#include<bits/stdc++.h>
using namespace std;
const int N = 510;
const int MAX = 1e8;

void test(){
    int n=0;int m=0;
    cin>>n>>m;
    vector<vector<int>>arr(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            arr[i][j]=0;
        }
    }
    for(int i=0;i<n;i++){
        int r=0;
        cin>>r;
        for(int j=0;j<r;j++){
            int index=0;
            cin>>index;
            arr[i][index-1]=0;
        }
    }

    for(int j=1;j<m;j++){
        if(arr[0][j]==0) break;
        
    }
    int num=MAX;
    for(int i=0;i<n;i++){
        for(int x=0;x<n;x++){
            
            for(int y=0;y<m;y++){
                if(x==0&&y==0){
                    
                    continue;
                }
                if(arr[x][y]!=0){
                    
                }
            }
            
        }
    }
    cout<<num<<"\n";
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t = 0; cin>>t;
    while(t--){
        test();
    }
    return 0;
}