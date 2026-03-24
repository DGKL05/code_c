#include <bits/stdc++.h>
using namespace std;
void solve(){
    int ans1 = 0,ans2 = 0;
    int num = 0;
    int idx = 1;
    string str;cin>>str;
    if(str.size()%2){
        cout<<-1;
        return;
    }
    for(int i = 0;i<str.size();++i){
        if(str[i]=='0')ans2++;
        else ans1++;
    }
    if(ans1!=ans2){
        cout<<-1;
        return;
    }
    cout<<ans1<<endl;
    ans1 = 0;ans2 = 0;
    for(int i = 0;i<str.size();++i){
        if(str[i]=='0'){
            if(ans1==0){
                cout<<idx<<' '<<1<<endl;
                ans2++;
            }else{
                idx++;
                ans1--;
            }
        }else{
            if(ans2==0){
                cout<<idx<<' '<<2<<endl;
                ans1++;
            }else{
                idx++;
                ans2--;
            }
        }
    }
}
int main()
{
    unordered_map<int,int>m1;
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}
