#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int arr[N];bool fa=true;int n=0;int m;int idx=1;char c;
int pre[N];int net[N];
void check(){
    if(arr[idx]==0){
        int temp=net[idx];
        int t1=pre[idx];
        pre[net[idx]]=t1;
        net[pre[idx]]=temp;
    }
}
void move()
{
    if(fa){
        idx=net[idx];

    }else{
        idx=pre[idx];
    }
}
void test()
{
    cin>>n>>m;
    int n2=n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i=1;i<=n;i++){
        if(i==1)pre[i]=n;
        else pre[i]=i-1;
        if(i==n) net[i]=1;
        else net[i]=i+1;
    }
    string s1;
    cin>>s1;
    s1=' '+s1;
    n++;
    for(int i=1;i<=m;i++){
        c=s1[i];
        if(c=='C'){
            arr[idx]--;
            check();
            move();
        }else if(c=='S'){
            arr[idx]--;
            // if(arr[idx]==0) n--;
            check();
            move();
            move();
        }else if(c=='R'){
            arr[idx]--;
            check();
            // if(arr[idx]==0) n--;
            if(fa) fa=false;
            else fa=true;
            move();
        }else{
            arr[idx]--;
            check();
            // if(arr[idx]==0) n--;
            move();
            arr[idx]+=2;
            move();
        }
        // for(int i=1;i<=n2;i++){
        //     cout<<arr[i]<<" ";
        // }
        // cout<<"\n";
    }
    for(int i=1;i<=n2;i++){
        cout<<arr[i]<<"\n";
    }
}

int main()
{
    int t=1;
    // cin>>t;
    while(t--) test();
    return 0;
}