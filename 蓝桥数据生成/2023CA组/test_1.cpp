#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll f(int x){
    if(x==1)return 1;
    return x*f(x-1);
}

 bool check_is_valid_order(std::queue<int> order) {
    std::stack<int> s;
    int n = order.size();
    for (int i = 1; i <= n; i++){
        s.push(i);
        while (!s.empty() && s.top()==order.front())
        {
        s.pop();
        order.pop();
        }
    }
    if (!s.empty()){
       return false;
    }
   return true;
 }

int main(){
    int n;cin>>n;
    vector<int>arr(n+1);
    for(int i = 1;i<=n;++i)arr[i]=i;
    int t = 0;
    ll sum = f(n);
    do{
        //cout<<"a ";
        // int is = 0;
        // for(int i = 2;i<=n-1;++i){
        //     if(arr[i-1]>arr[i+1]&&arr[i]<arr[i+1])is=1;
        // }
        queue<int>q1;
        for(int i =1 ; i<=n;i++) q1.push(arr[i]);
         if(!check_is_valid_order(q1))continue;
        t++;
        if(t>20||t>sum)break;
        for(int i = 1;i<=n;++i)cout<<arr[i];
        if(t==sum||t==20)break;
        cout<<"\n";
    }while(next_permutation(arr.begin()+1,arr.end()));
    return 0;
}