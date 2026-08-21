#include<bits/stdc++.h>
/*
    100 - 60 + 15 = 55;
    55 45 145
    60
*/
using namespace std;
using ll = long long;

void test(){
    int q=0;ll v=0;
    cin>>q>>v;
    // map<ll,ll>ru;
    map<ll,ll>dao;
    while(q--){
        int op = 0;
        ll ti=0;
        cin>>op>>ti;
        if(op == 1){
            ll w = 0;
            cin>>w;
            dao[v - w + ti]++;
        }else {
            if(dao.size() == 0){
                cout<<-1<<"\n";
                continue ;
            }
            auto it = dao.upper_bound(ti);
            if(it == dao.begin()){
                // it = dao.end();
                // it --;
                cout<<min(v - ((it ->first)- ti) , v)<<"\n";
                it->second--;
                if(it->second == 0) dao.erase(it);
            }else{
                it --;
                cout<<min(v - ((it ->first)- ti) , v)<<"\n";
                it->second--;
                if(it->second == 0) dao.erase(it);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    // cin>>T;
    while(T--) test();
    return 0;
}