#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    vector<vector<int>>arr(3,vector<int>(3));
    vector<int>fa(10,0);
    bool t = true;
    int ans1=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>arr[i][j];
            fa[arr[i][j]]++;
            if(i == j) ans1+=arr[i][j];
            if(fa[arr[i][j]] >= 2) t=false;
        }
    }
    set<int>s1;
    s1.insert(ans1);
    
    for(int i=0;i<3;i++){
        int num=0;
        for(int j=0;j<3;j++){
            num+=arr[i][j];
        }
        s1.insert(num);
    }
    for(int i=0;i<3;i++){
        int num=0;
        for(int j=0;j<3;j++){
            num+=arr[j][i];
        }
        s1.insert(num);
    }
    int ans2=arr[1][1] + arr[2][0] + arr[0][2];
    s1.insert(ans2);
    // cout<<ans1<<" "<<ans2<<"\n";
    if(!t || s1.size() > 1) {
        cout<<"No\n";
    }else cout<<"Yes\n";
    
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