#include<bits/stdc++.h>
using namespace std;
using ll =long long;
const int N = 2*1e5+5;
struct node{
    int st;int en;
    bool operator <(const node &a) const {
        return a.st > st;
    }
};
set<node>s1;map<node,int>m1;
int arr[N][4];

void move(int &idx,int i)
{
    // cout<<" move : "<<arr[i][idx]<<" "<<i<<" "<<idx<<"\n";
    if(idx==3 || arr[i][idx]==0) idx=1;
    else idx++;
    if(arr[i][idx]==0) idx=1;
}

void test()
{
    int n=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        int d=0;
        cin>>d;
        for(int j=1;j<=d;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    int i=1;
    for(int sta=1;sta<=n;sta++){
        int temp=i;
        s1.clear();m1.clear();
        // cout<<i<<"\n";
        int idx=1;
        while(m1[{i,idx}]!=2){
            s1.insert({i,arr[i][idx]});
            // cout<<" dang : "<<arr[i][idx]<<" "<<i<<" "<<idx<<"\n";
            i=arr[i][idx];
            m1[{i,idx}]++;
            move(idx,i);
            // cout<<idx<<"\n";
            cout<<" move : "<<arr[i][idx]<<" "<<i<<" "<<idx<<"\n";
        }
        cout<<s1.size()<<"\n";
        for(auto [l,r] : s1) cout<<l<<" -> "<<r<<"\n";
        i=temp+1;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}