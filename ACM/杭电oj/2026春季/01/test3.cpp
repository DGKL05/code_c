#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    string s1;
    cin>>s1;
    set<int>st;
    int n = s1.size();
    for(int i=0;i<n;i++){
        st.insert(s1[i] - '0');
    }
    cout<<"int[] arr = new int[]{";
    vector<int>arr;
    for(auto x:st) arr.push_back(x);
    int idx = 0;
    map<int,int>m1;
    for(int i=arr.size()-1;i>=0;i--){
        cout<<arr[i];
        m1[arr[i]] = idx++;
        if(i != 0) cout<<",";
    }
    cout<<"}\n";
    cout<<"int[] index = new int[]{";
    
    for(int i=0;i<n;i++){
        cout<<m1[s1[i] - '0'];
        if(i != n-1) cout<<",";
    }
    cout<<"}";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}