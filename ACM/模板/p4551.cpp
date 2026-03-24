#include <bits/stdc++.h>
using namespace std;
using ll =long long;
string s;
const int N = 5*1e6+10;
int max_cnt=0;
struct trie {
    int nex[N][2], cnt;
    // bool vis[N];// 该结点结尾的字符串是否存在
    void insert(string &s,int l) {  // 插入字符串
        int p = 0;
        for(int i=l-1;i>=0;i--) {
            int c = s[i]-'0';
            if (!nex[p][c]) nex[p][c] = ++cnt;  // 如果没有，就添加结点
            p = nex[p][c];
            
        }
        max_cnt=max(max_cnt,l);
        // cout<<max_cnt<<"\n";
        // cout<<cnt<<"\n";
    }
    ll get(string &s,int l) {  // 查找字符串
        int p = 0;ll ans=0;int k=0;bool fa=true;
        int temp=max_cnt;
        // cout<<s<<"\n";
        if(l<temp){
            if(nex[p][1]){
                ans+=(ll)pow(2,temp-1);
                p=nex[p][1];
            }else{
                p=nex[p][0];
            }
            // cout<<"NO : "<<ans<<' ';
            temp--;
        }
        // p=0;
        for(int i=l-1;i>=0;i--){
            // cout<<i<<" : \n";
            int c = s[i] - '0';int t=-1;
            
            if(c==0) t=1;
            else t=0;
            // cout<<"c = "<<c<<" t = "<<t<<"\n";
            // cout<<"net = "<<nex[p][t]<<"\n";
            if (!nex[p][t]) {
                if(c==1){
                    ans+=(ll)pow(2,temp-1);
                    // cout<<"NULL : i = "<<i<<"\n";
                }
                temp--;
            }else{
                ans+=(ll)pow(2,temp-1);
                // cout<<"YES : i = "<<i<<"\n";
                temp--;
            }
            // cout<<ans<<' ';
            p = nex[p][c];
        }
        // cout<<ans<<"\n";
      return ans;
    }
  }str_t;

int main()
{
    set<int>s1;
    int n=0;ll num=0;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int u,v,w;
        cin>>u>>v>>w;
        int temp=w;
        s="";
        while(w){
            if(w&1) s+='1';
            else s+='0';
            w>>=1;
        }
        str_t.insert(s,s.size());
        s1.insert(temp);
    }
    for(int w:s1){
        s="";
        while(w){
            if(w&1) s+='1';
            else s+='0';
            w>>=1;
        }
        num=max(num,str_t.get(s,s.size()));
    }
    cout<<num<<"\n";
	return 0;
}
