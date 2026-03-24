#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    vector<int>a1(3),a2(3);
    for(int i=0;i<n;i++){
        int c=0;int k=0;
        cin>>c>>k;
        k--;
        if(c == 0){
            a1[k]++;
        }else {
            a2[k]++;
        }
    }
    n=3;
    for(int i=0;i<n;i++){
        cout<<a1[i];
        if(i!=n-1) cout<<" ";
    }
    cout<<"\n";
    for(int i=0;i<n;i++){
        cout<<a2[i];
        if(i!=n-1) cout<<" ";
    }
    cout<<"\n";
    bool fa=true;
    for(int i=0;i<n;i++){
        if(a2[i]>a1[i]){
            fa=false;
            break;
        }else if(a2[i]<a1[i]) break;
    }
    if(fa) cout<<"The first win!";
    else cout<<"The second win!";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}