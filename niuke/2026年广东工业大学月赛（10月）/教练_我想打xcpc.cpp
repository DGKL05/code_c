#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

struct node{
    string name;
    string cty;
    string ti;
    int sta;
};

void test(){
    int n=0;
    cin>>n;
    vector<node>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i].name>>arr[i].cty>>arr[i].ti>>arr[i].sta;
    }

    for(int i=0;i<n;i++){
        if(arr[i].sta == 1){
            cout<<"gdut_"<<arr[i].name<<" "<<arr[i].cty<<" "<<arr[i].ti<<"\n";
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T = 1;
    // cin>>T;
    while(T--) test();
    return 0;
}