#include <bits/stdc++.h>
using namespace std;
string s1,s;

struct trie {
    int nex[500010][26], cnt;
    int ans[500010];// 该结点结尾的字符串是否存在
  
    void insert(string &s) {  // 插入字符串
      int p = 0;int l=s.size();
      for (int i = 0; i < l; i++) {
        int c = s[i] - 'a';
        if (!nex[p][c]) nex[p][c] = ++cnt;  // 如果没有，就添加结点
        p = nex[p][c];
      }
      ans[p] = true;
    }
    int find(string &s) {  // 查找字符串
      int p = 0;int l=s.size();
      for (int i = 0; i < l; i++) {
        int c = s[i] - 'a';
        if (!nex[p][c]) return 0;
        p = nex[p][c];
      }
      return ans[p] ? ans[p]++ : 0 ;
    }
  }t;

int main()
{
    int n=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s1;
        t.insert(s1);
    }
    int m=0;
    cin>>m;
    while(m--){
        cin>>s;
        if(t.find(s)==1){
            cout<<"OK\n";
        }else if(t.find(s)>1){
            cout<<"REPEAT\n";
        }else{
            cout<<"WRONG\n";
        }
    }
	return 0;
}
