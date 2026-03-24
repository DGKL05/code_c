#include<bits/stdc++.h>
using namespace std;
using ll =long long;
const int N = 5e4+5;
int sta[N];
struct Point {
    int x, y;int id;
    Point operator-(const Point& rhs) const {
        return {x - rhs.x, y - rhs.y};
    }
    double operator*(const Point& b) const {
        return x * b.y - y * b.x;
    }
} p[N],h[N];
int stk[N];int used[N];;
bool cmp(Point &a,Point &b){
    if(a.x==b.x) return a.y>b.y;
    else return a.x>b.x;
}

double sol(int i,int j){ return (double)(p[i].y - p[j].y)/(double)(p[j].x - p[i].x); }

void test()
{
    int n=0;
    cin>>n;
    for(int i=1;i<=n;i++) {
        int a,b;
        cin>>a>>b;
        p[i].x=a;p[i].y=b;p[i].id=i;
    }
    int tp = 0;                       // 初始化栈
    std::sort(p + 1, p + 1 + n,cmp);  // 对点进行排序
    // stk[++tp] = 1;
    // 栈内添加第一个元素，且不更新 used，使得 1 在最后封闭凸包时也对单调栈更新
    for (int i = 1; i <= n; ++i) {
        if(p[i].x==p[i-1].x && i!=1)  continue;
        while (tp > 1 && sol(stk[tp],i) >= sol(stk[tp],stk[tp-1])) tp--;
        stk[++tp] = i;
    }
    for (int i = 1; i <= tp; ++i)  // 复制到新数组中去
        stk[i] = p[stk[i]].id;
    // cout<<tp<<"\n";
    sort(stk+1,stk+1+tp);
    for(int i=1;i<=tp;i++) cout<<stk[i]<<' ';
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}