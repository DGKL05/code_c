#include<bits/stdc++.h>
using namespace std;
using ll =long long;

template <class Type> 
Type stringToNum(const string& str){ 
    istringstream iss(str); 
    Type num; 
    iss >> num; 
    return num;     
} 

void test()
{
    ll n=0;
    cin>>n;
    string s1="10";
    ll num=stringToNum<ll>(s1);
    num++;
    set<ll>st;
    // if(n%2==0){
    //     st.insert(n/num);
    // }
    if(n%num==0){
        st.insert(n/num);
    }
    for(int i=1;i<=18;i++){
        s1=s1+'0';
        num=stringToNum<ll>(s1);
        num++;
        if(n%num==0){
            st.insert(n/num);
        }
    }
    cout<<st.size()<<"\n";
    if(st.size()==0){
        return ;
    }
    for(auto x:st){
        cout<<x<<" ";
    }
    cout<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}