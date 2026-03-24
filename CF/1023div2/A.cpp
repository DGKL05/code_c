#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    vector<int>v2(n);//前i个数的GCD
    set<int>s1;
    int ans=-1;bool fa=true;
    for(int i=0;i<n;i++){
        int num=0;
        cin>>num;
        v2[i]=num;
        ans=max(ans,num);
        s1.insert(num);
    }
    
    if(s1.size()==1) cout<<"NO\n";
    else {
        cout<<"YES\n";
        for(int i=0;i<n;i++){
            if(v2[i]!=ans){
                cout<<"1 ";
            }else cout<<"2 ";
        }
        cout<<"\n";
    }
    // return ;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int t=0;
    cin>>t;
    while(t--) test();
    return 0;
}