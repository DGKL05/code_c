#include <bits/stdc++.h>
using namespace std;
using ll =long long;
int arr[7]={0};

int dfs(int index,int n,int m)
{   if(index == 7){
        //cout<<"ok\n";
       // return 1;
        if(n == 0 && m == 0 ){
            //cout<<ans<<'\n';
            return 1;
            //num++;
        }else return 0;
    }
    //if(arr[index]>5) return 0;
    int num=0;
    for(int j=0;j<=n;j++){
        for(int k=0;k<=m;k++){
            arr[index]+=(j+k);
            if(arr[index]>=2&&arr[index]<=5) num += dfs(index+1,n-j,m-k);
            arr[index]-=(j+k);
        }
    }
    
    return num;
}

int main()
{
    int ans = dfs(0,9,16);
    cout<<ans<<"\n";    
    return 0;
}