#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    vector<string>arr(n);
    int ans=0;
    for(auto &x : arr) {
        cin>>x;
        ans = max(ans,(int)x.size());
    }
    // cout<<"ans = "<<ans<<"\n";
    for(int i=0;i<n;i++){
        if((arr[i].size() - ans) %2 == 0){
            int n1 = arr[i].size();
            // cout<<"n1 = "<<(n1 - ans)/2<<"\n";
            for(int i=0;i<(ans - n1)/2;i++){
                cout<<".";
            }
            cout<<arr[i];
            for(int i=0;i<(ans - n1)/2;i++){
                cout<<".";
            }
            cout<<"\n";
        }
    }
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
