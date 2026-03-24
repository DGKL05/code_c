#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    ll ans=0;int num=0;
    cin>>ans;
    vector<ll>s1;
    s1.push_back(0);
    for(int i=0;i<n-2;i++){
        int a=0;cin>>a;
        s1.push_back(a);
    }
    sort(s1.begin(),s1.end());
    int n2=n-2;int idx=0;
    cin>>num;
    if(n == 2){
        if(ans*2>=num){
            cout<<"2\n";
            return ;
        }else {
            cout<<"-1\n";
            return ;
        }
    }
    int n1=2;
    while(ans*2<num){
        ll l=idx;ll r=n2;ll mid=(l+r+1)/2;
        int temp=-1;
         while(l < r){
            mid = (l + r + 1) / 2;
            if(s1[mid] <= 2*ans) { 
                l = mid;
                temp=1;
            }else{
                r= mid - 1; 
            }
            if(s1[l] > 2*ans) {
                cout<<"-1\n";
                return ;
            }
        }
        if(temp==-1) {
            cout<<"-1\n";
            return ;
        }
        idx=l;
        ans=s1[l];
        n1++;
    }
    cout<<n1<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}
