#include <bits/stdc++.h>
using namespace std;

void test()
{
    int n=0;int x=0;int y=0;int cnt_0=0;int cnt_1=0;
    cin>>n>>x>>y;
    vector<int>v1(n);
    for(int i=0;i<n;i++){
        cin>>v1[i];
        if(v1[i]==0) cnt_0++;
        else cnt_1++;
    }
    if(v1[n-1]==1){
        if(x!=0){
            for(int i=0;i<y;i++){
                cout<<"1 ";
            }
            for(int i=0;i<x;i++){
                cout<<"0 ";
            }
            cout<<"\n";
            return ;
        }else {
            if(cnt_1 == n){
                for(int i=0;i<y;i++){
                    cout<<"1 ";
                }
                cout<<"\n";
                return ;
            }else {
                cout<<"-1\n";
                return ;
            }
        }
    }else {
        if(x==0){
            cout<<"-1\n";
            return ;
        }else {
            vector<int>ans;int cnt=1;int idx=-1;
            // ans.push_back(0);
            for(int i=n-2;i>=0;i--){
                if(v1[i] == 0) cnt++;
                else {
                    idx=i;
                    break;
                }
            }
            if(cnt>x){
                cout<<"-1\n";
                return ;
            }
            int temp=x;
            x=x-cnt;
            if(x!=0){
                for(int i=0;i<y;i++){
                    cout<<"1 ";
                }
                for(int i=0;i<temp;i++){
                    // ans.push_back(0);
                    cout<<"0 ";
                }
                cout<<"\n";
                return ;
            }else {
                for(int i=0;i<idx;i++){
                    if(v1[i]==0){
                        cout<<"-1\n";
                        return ;
                    }
                    
                }
                for(int i=0;i<y;i++){
                    cout<<"1 ";
                }
                for(int i=0;i<temp;i++){
                    cout<<"0 ";
                }
                cout<<"\n";
                return ;
            }
        }
    }
}

int main() {
    int T=1;
    cout<<(int)(1 or 0)<<"\n";
    cout<<(int)(0&0|1|0|0)<<"\n";
    return 0;
}