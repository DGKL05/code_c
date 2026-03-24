#include<bits/stdc++.h>
using namespace std;
using ll =long long;

const int N=400005;
struct node{
    int l,r;
}a[N];
bool cmp(node a,node b){
    return a.l<b.l;
}

void test()
{
    int n,m;cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>a[i].l>>a[i].r;
    sort(a+1,a+1+m,cmp);
    set<int>s;int la=0;
    for(int i=m;i>=1;i--){
        if(la>=a[i].l&&la<=a[i].r) continue;
        else {
            s.insert(a[i].l);la=a[i].l;
        }
    } 
    string ans(2*n+1,' ');
    for(auto i:s){
        ans[i]='(';
    }
    int k=n-s.size();
    for(int i=1;i<=2*n;i++){
        if(k<=0) {
            break;
        }
        if(ans[i]!='(') ans[i]='(',k--;
    }
    for(int i=1;i<=2*n;i++) if(ans[i]!='(') ans[i]=')';
    stack<int>tmp;
    for(int i=1;i<=2*n;i++){
        if(ans[i]=='(') tmp.push(1);
        else{
            if(tmp.empty()) {
                cout<<-1<<endl;return;
            } 
            else tmp.pop();
        }
    }
    if(tmp.size()){
        cout<<-1<<endl;return;
    }
    for(int i=1;i<=2*n;i++) cout<<ans[i];cout<<endl;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}