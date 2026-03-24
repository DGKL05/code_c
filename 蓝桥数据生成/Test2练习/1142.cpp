#include<bits/stdc++.h>
using namespace std;
using ll =long long;
const int N = 7*1e5+5;

ll arr[N];

int main(){
    int n=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    stack<pair<ll,int>>q1;
    q1.push({arr[0],1});
    cout<<"-1 ";
    for(int i=1;i<n;i++){
        pair<ll,int>temp = q1.top();
        ll num=temp.first;

        if(arr[i]>num){
            bool fa=false;
            while(q1.size()){
                pair<ll,int>temp = q1.top();
                ll num=temp.first;
                if(arr[i]>num){
                    q1.pop();
                }else {
                    cout<<temp.second<<' ';
                    q1.push({arr[i],i+1});
                    fa=true;
                    break;
                }
            } 
            if(!fa) {
                cout<<"-1 ";
                q1.push({arr[i],i+1});
            }
        }else {
            cout<<temp.second<<' ';
            q1.push({arr[i],i+1});
        }
    }
    while(q1.size()) q1.pop();
    stack<int>v1;
    // q1.clear();
    q1.push({arr[n-1],n});
    cout<<"\n";
    for(int i=n-2;i>=0;i--){
        pair<ll,int>temp = q1.top();
        ll num=temp.first;

        if(arr[i]>num){
            bool fa=false;
            while(q1.size()){
                pair<ll,int>temp = q1.top();
                ll num=temp.first;
                if(arr[i]>num){
                    q1.pop();
                }else {
                    v1.push(temp.second);
                    //cout<<temp.second<<' ';
                    q1.push({arr[i],i+1});
                    fa=true;
                    break;
                }
            } 
            if(!fa) {
                //cout<<"-1 ";
                v1.push(-1);
                q1.push({arr[i],i+1});
            }
        }else {
            //cout<<temp.second<<' ';
            v1.push(temp.second);
            q1.push({arr[i],i+1});
        }
        
    }
    while(v1.size()){
        cout<<v1.top()<<' ';
        v1.pop();
    }
    cout<<"-1";
    return 0;
}