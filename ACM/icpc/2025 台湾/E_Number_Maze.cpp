#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    string s1;int idx1=0;int idx2=0;
    cin>>s1>>idx1>>idx2;
    string x;string y;
    int k=0;
    // if(idx1 == k){
    //     x = s1;
    //     idx1 = k;
    // }
    // if(idx2 == k){
    //     y = s1;
    //     idx2 = k;
    // }
    // cout<<"x = "<<x<<" y = "<<y<<"\n";
    do{
        // cout<<"k = "<<k<<" s1 = "<<s1<<"\n";
        k++;
        if(idx1 == k){
            x = s1;
            idx1 = k;
        }
        if(idx2 == k){
            y = s1;
            idx2 = k;
        }
        if(x.size() != 0 && y.size() != 0) break;
    }while(next_permutation(s1.begin(),s1.end()));
    // cout<<"x = "<<x<<" y = "<<y<<"\n";
    set<char>st;
    int ans = 0;
    int ans1 = 0;
    int n = s1.size();
    vector<bool>fa(n,false);
    for(int i=0;i<n;i++){
        if(x[i] == y[i]) ans++,fa[i] = true;;
    }
    for(int i=0;i<n;i++){
        if(!fa[i]) st.insert(x[i]);
    }
    for(int i=0;i<n;i++){
        if(!fa[i] && st.find(y[i]) != st.end()) ans1++;
    }
    cout<<ans<<"A"<<ans1<<"B\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}