#include<bits/stdc++.h>
using namespace std;
using ll =long long;
int a[3] = {5,2,1};
void test()
{
    int n=0;
    cin>>n;
    multiset<int>s1;
    for(int i=0;i<n;i++){
        int num = 0;
        cin>>num;
        s1.insert(num);
    }
    vector<int>arr;
    while(s1.size()>0){
        auto it = s1.end();
        it--;
        int num = *it;
        if(num>=0) num/=5;
        // else num*=-1;
        arr.push_back(num);
        for(int i=0;i<3;i++){
            s1.erase(s1.find(num*a[i]));
        }
    }
    sort(arr.begin() , arr.end());
    for(int i = arr.size() - 1 ; i >= 0 ; i--){
        cout<<arr[i];
        if(i!=0) cout<<" ";
    }
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