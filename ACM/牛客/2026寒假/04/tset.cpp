#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    int num = pow(2,n);
    vector<int>a(num,0);
    for(int i=0;i<num;i++) a[i] = i;
    vector<int>ans(n);
    int min_num=1e9;
    do{
        int k = 0;
        for(int i=0;i<num-1;i++){
            k+=a[i] ^ a[i+1];
        }
        if(k < min_num) {
            ans = a;
            min_num = k;
        }
    }while(next_permutation(a.begin() , a.end()));
    for(auto x:a) cout<<x<<" ";
    cout<<"\n";
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