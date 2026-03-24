#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int n=0;
int pre[N];int sz[N];



struct dsu {
  vector<size_t> pa;

  explicit dsu(size_t size_)
      : pa(size_ +1 ){
    for(size_t i = 1 ; i < size_+1; i++){
      pa[i]=i;
    }
  }
  //合并
  void unite(size_t x, size_t y) {
    x = find(x), y = find(y);
    if (x == y) return;
    pa[y] = x;
  }
  //移动
  void move(size_t x, size_t y) {
    auto fx = find(x), fy = find(y);
    if (fx == fy) return;
    pa[x] = fy;
    
  }
  //查询
  size_t find(size_t x) { return pa[x] == x ? x : pa[x] = find(pa[x]); }
};

void test(){
  cin>>n;
  int q=0;
  cin>>q;
  dsu dsu(n);
  for(int i=0;i<q;i++){
    int so=0;int a=0;int b=0;
    cin>>so;
    if(so==1){
      cin>>a>>b;
      dsu.unite(a,b);
      for(size_t i = 1 ; i < n+1; i++){
        cout<<dsu.pa[i]<< " ";
      }
      cout<<"\n";
    }else if(so==2){
      cin>>a>>b;
      dsu.move(a,b);
      for(size_t i = 1 ; i < n+1; i++){
        cout<<dsu.pa[i]<< " ";
      }
      cout<<"\n";
    }else if(so==3){
      cin>>a>>b;
      // for(int i=1;i<=n;i++){
      //   if(dsu.find(i) == a){
          //dsu.move(a , b);
      //   }
      // }
      int a1=dsu.find(a);
      int b1=dsu.find(b);
      // dsu.pa[a1]=b1;
      // dsu.pa[b1]=a1;
      dsu.move(a1 , b1);
      dsu.move(b1 , a1);
      for(size_t i = 1 ; i < n+1; i++){
        cout<<dsu.pa[i]<< " ";
      }
      cout<<"\n";
    }else if(so==4){
      cin>>a;
      int index=dsu.find(a);
      cout<<index<<"\n";
    }
  }
}

int main() {
  int t=0;
  cin>>t;
  while(t--) test();
  return 0;
}