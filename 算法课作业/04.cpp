#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n=0;
    cin>>n;
    map<int,int>m1;
    for(int i=0;i<n;i++){
        int num=0;
        cin>>num;
        m1[num]++;
    }
    if(n%=1){
        n++;
    }
    auto it=m1.begin();
    while(it!=m1.end()){
        if(it->second>=n) {
            cout<<it->first<<"\n";
            return 0;
        }
        it++;
    }
    cout<<"-1\n";
    return 0;
}