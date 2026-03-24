#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define int ll
#define endl "\n"
const int INF=__INT_MAX__;
void solve(){
    string s;cin>>s;
    vector<int>nxt_l(s.size(),INF),nxt_r(s.size(),INF);//S中每个字符的下个L/R位置表
    int l=INF,r=INF;
    for(int i=s.size()-1;i>=0;i--){//倒序遍历S进行预处理
        nxt_l[i]=l,nxt_r[i]=r;
        if(s[i]=='L') l=i;
        else r=i;
    }

    int q;cin>>q;
    while(q--){
        string t;cin>>t;
        bool ok=1;
        if ((s[0]=='L'&&s[0]!=t[0])||(s[s.size()-1]=='R'&&t[t.size()-1]!=s[s.size()-1])) {//2个特例
            cout<<"NO"<<'\n';
            continue;
        }
        int idx=(t[0]=='L')?l:r;//预处理后l/r即为S中首个L/R的位置
        if (idx>=s.size()) {
            cout<<"NO"<<'\n';
            continue;
        }
        for (int i=1;i<t.size();i++) {
            idx=(t[i]=='L')?nxt_l[idx]:nxt_r[idx];
            if (idx>=s.size()) {
                ok=0;
                break;
            }
        }
        if(ok) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}
