#include<bits/stdc++.h>
using namespace std;
using ll =long long;
const int N = 1e5+5;
int sta[N];
struct Point {
    double x, y, ang;
    Point operator-(const Point& p) const { return {x - p.x, y - p.y, 0}; }
} p[N];
  
    double dis(Point p1, Point p2) {
        return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
    }
    
    bool cmp(Point p1, Point p2) {
        if (p1.ang == p2.ang) {
        return dis(p1, p[1]) < dis(p2, p[1]);
        }
        return p1.ang < p2.ang;
    }
    
    double cross(Point p1, Point p2) { return p1.x * p2.y - p1.y * p2.x; }

    double js (int a,int b){
        double numa=pow(p[a].x-p[b].x,2);
        double numb=pow(p[a].y-p[b].y,2);
        return (double)(sqrt(numa+numb));
    }
void test()
{
    int n=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        double x,y;
        cin>>x>>y;
        p[i].x=x;p[i].y=y;
    }
    for (int i = 2; i <= n; ++i) {
        if (p[i].y < p[1].y || (p[i].y == p[1].y && p[i].x < p[1].x)) {
            std::swap(p[1], p[i]);
        }
      }
      for (int i = 2; i <= n; ++i) {
        p[i].ang = atan2(p[i].y - p[1].y, p[i].x - p[1].x);
      }
      std::sort(p + 2, p + n + 1, cmp);
      int top=0;
      sta[++top] = 1;
      for (int i = 2; i <= n; ++i) {
        while (top >= 2 && cross(p[sta[top]] - p[sta[top - 1]], p[i] - p[sta[top]]) < 0) {
          top--;
        }
        sta[++top] = i;
    }
    // cout<<"top = "<<top<<"\n";
    // for(int i=1;i<=top;i++){
    //     cout<<sta[i]<<' ';
    // }
    double ans=0;
    for(int i=1;i<=top-1;i++){
        ans+=js(sta[i],sta[i+1]);
        // cout<<"juli = "<<js(sta[i],sta[i+1])<<"\n";
    }
    ans+=js(sta[1],sta[top]);
    cout<< fixed << setprecision(2) << ans <<"\n";
}

signed main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}