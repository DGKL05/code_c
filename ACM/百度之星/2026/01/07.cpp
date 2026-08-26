#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(vector<int>&arr,int ma){
    int num = 0;
    for(auto x:arr){
        if(x == ma) num++;
    }
    if(num > 1) return false;
    return true;
}

void test(){
    int n=0;
    cin>>n;
    vector<int>arr(n);
    int ans = 0;
    int fu =0;
    int ma = 0;
    // int ii = 0;
    int idx=0;
    int nm=0;
    for(int i=0;i<n;i++){
        int x = 0;
        cin>>x;
        arr[i] = x;
        if(x > ma){
            ma = x;
            idx = i;
        }
        if(x != -1) ans+=x,nm++;
        else fu++;
    }
    if(fu == 0){
        cout<<idx + 1 <<"\n";
        return ;
    }
    set<int>s1;
    if(n - ans > ma){
        for(int i=0;i<n;i++){
            if(arr[i] == -1) s1.insert(i);
        }
    }
    int k = (n - ans)/fu;
    if((n - ans)%fu != 0) k++;
    if(k < ma && check(arr,ma)) s1.insert(idx);

    for(auto x:s1) {
        cout<<x+1<<" ";
    }
    cout<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin>>T;
    while(T--) test();
    return 0;
}