#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void sw_ap(int &a,int &b){
    int temp = b;
    b = a;
    a = temp;
    // cout<<"a = "<<a<<" b = "<<b<<"\n";
}
void test()
{
    int n=0;
    cin>>n;
    int min_idx=-1;
    int max_idx=-1;
    int min_arr=1000000;
    int max_arr=-1;
    vector<int>arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i] < min_arr){
            min_arr = arr[i];
            min_idx = i;
        }
        if(arr[i] > max_arr){
            max_arr = arr[i];
            max_idx = i;
        }
    }
    // cout<<min_idx<<" "<<max_idx<<"\n";
    swap(arr[0],arr[min_idx]);
    if(max_idx == 0) max_idx = min_idx;
    swap(arr[n-1],arr[max_idx]);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
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
