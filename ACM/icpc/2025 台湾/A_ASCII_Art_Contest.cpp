#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    vector<int>arr(3,0);
    int mav=-1;int miv=1e8;
    for(int i=0;i<3;i++){
        cin>>arr[i];
        mav = max(mav,arr[i]);
        miv = min(miv,arr[i]);
    }
    if(mav - miv >= 10){
        cout<<"check again\n";
    }else {
        sort(arr.begin(),arr.end());
        cout<<"final "<<arr[1]<<"\n";
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}