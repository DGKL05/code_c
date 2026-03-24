#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    vector<int>v1(n);set<int>s1;
    int l1=0;
    for(int i=0;i<n;i++){
        cin>>v1[i];
        s1.insert(v1[i]);
        if(v1[i]!=v1[0]&&!l1) l1=i;
    }
    if(n==1){
        cout<<"1 1\n";
        return ;
    }
    ll max_num=n-s1.size();
    if(max_num==0){
        cout<<1<<' '<<n<<"\n";
        return ;
    }
    int r3=0;int l_max=0;
    for(int r=n-1;r>=l1;r--){
        set<int>s2;
        s2.insert(v1[0]);
        for(int i=n-1;i>r;i--){
            s2.insert(v1[i]);
        }
        ll num=n-(r-l1+1)-s2.size();
        
        if(num==max_num){
            l_max=(r-l1+1);
            r3=r;
            break;
        }
    }
    int r1=n-1;int l3=0;int r_max=0;
    for(int i=n-1;i>=0;i--){
        if(v1[i]!=v1[n-1]&&r1==n-1) r1=i;
    }
    for(int l=0;l<=r1;l++){
        set<int>s2;
        s2.insert(v1[n-1]);
        for(int i=0;i<l;i++){
            s2.insert(v1[i]);
        }
        ll num=n-(r1-l+1)-s2.size();
        
        if(num==max_num){
            r_max=r1-l+1;
            l3=l;
            break;
        }
    }
    if(l_max==r_max&&l_max==0){
        cout<<0<<"\n";
        return ;
    }
    if(l_max>r_max){
        cout<<l1+1<<" "<<r3+1<<"\n";
    }
    else cout<<l3+1<<" "<<r1+1<<"\n";
    
}

int main()
{
    int t=0;
    cin>>t;
    while(t--){
        test();
    }
}