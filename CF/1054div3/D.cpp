#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    string s1;
    cin>>s1;
    vector<int>a,b;
    for(int i=0;i<n;i++){
        if(s1[i] == 'a') a.push_back(i);
        else b.push_back(i);
    }
    if(a.size() == 0 || b.size() == 0){
        cout<<"0\n";
        return ;
    }
    ll ans1=0;ll ans2=0;
    int num = a[a.size()/2];
    for(int i=0;i<a.size();i++){
        ans1+=1LL*(abs(a[i]-num)-abs((int)a.size()/2-i));
    }
    int num1 = b[b.size()/2];
    for(int i=0;i<b.size();i++){
        ans2+=1LL*(abs(b[i]-num1)-abs((int)b.size()/2-i));
    }
    cout<<min(ans1,ans2)<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}