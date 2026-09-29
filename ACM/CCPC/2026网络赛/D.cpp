#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using i128 = __int128_t;
using ld = long double;

struct Point{
    ll x,y;
};

i128 cross(ll ax,ll ay,ll bx,ll by){
    return (i128)ax*by-(i128)ay*bx;
}

i128 cross(Point a,Point b,Point c){
    return cross(b.x-a.x,b.y-a.y,c.x-a.x,c.y-a.y);
}

vector<Point> getHull(vector<Point>&p){
    int n=p.size();
    if(n<=2) return p;
    deque<Point>q;
    if(cross(p[0],p[1],p[2])>0){
        q.push_back(p[2]);
        q.push_back(p[0]);
        q.push_back(p[1]);
        q.push_back(p[2]);
    }else{
        q.push_back(p[2]);
        q.push_back(p[1]);
        q.push_back(p[0]);
        q.push_back(p[2]);
    }
    for(int i=3;i<n;i++){
        Point now=p[i];
        if(cross(q[0],q[1],now)>=0&&cross(q[q.size()-2],q.back(),now)>=0) continue;
        while(q.size()>=2&&cross(q[0],q[1],now)<=0) q.pop_front();
        q.push_front(now);
        while(q.size()>=2&&cross(q[q.size()-2],q.back(),now)<=0) q.pop_back();
        q.push_back(now);
    }
    q.pop_back();
    vector<Point>h(q.begin(),q.end());
    i128 s=0;
    for(int i=0;i<(int)h.size();i++){
        int j=(i+1)%h.size();
        s+=(i128)h[i].x*h[j].y-(i128)h[i].y*h[j].x;
    }
    if(s<0) reverse(h.begin(),h.end());
    return h;
}

void test(){
    int n;
    ll w,u,v;
    cin>>n>>w>>u>>v;
    vector<Point>p(n);
    for(int i=0;i<n;i++) cin>>p[i].x>>p[i].y;
    vector<Point>h=getHull(p);
    int m=h.size();
    const ld INF=1e100L;
    i128 A=(i128)v*v-(i128)u*u;
    auto dis=[&](ll dx,ll dy)->ld{
        if(dx==0&&dy==0) return 0;
        i128 B=(i128)u*dx;
        i128 R=(i128)dx*dx+(i128)dy*dy;
        i128 D=(i128)v*v*dx*dx+A*(i128)dy*dy;
        if(A<0){
            if(B>=0||D<0) return INF;
        }else if(A==0){
            if(B>=0) return INF;
        }
        if(D<0) return INF;
        ld b=(ld)B;
        ld d=sqrtl((ld)D);
        if(b<=0){
            ld down=d-b;
            if(down<=0) return INF;
            return (ld)R/down;
        }
        return (b+d)/(ld)A;
    };
    vector<ld>direct(m,INF);
    vector<ld>go1(m,INF),go2(m,INF);
    for(int i=0;i<m;i++){
        if(h[i].y==w){
            direct[i]=0;
        }else{
            int pre=(i-1+m)%m;
            int nxt=(i+1)%m;
            ll ax=h[i].x-h[pre].x;
            ll ay=h[i].y-h[pre].y;
            ll bx=h[nxt].x-h[i].x;
            ll by=h[nxt].y-h[i].y;
            i128 c1=cross(ax,ay,-u,v);
            i128 c2=cross(bx,by,-u,v);
            if(!(c1>0&&c2>0)) direct[i]=(ld)(w-h[i].y)/(ld)v;
        }
        int nxt=(i+1)%m;
        int pre=(i-1+m)%m;
        go1[i]=dis(h[nxt].x-h[i].x,h[nxt].y-h[i].y);
        go2[i]=dis(h[pre].x-h[i].x,h[pre].y-h[i].y);
    }
    vector<ld>dp1=direct;
    for(int t=0;t<2;t++){
        for(int i=m-1;i>=0;i--){
            int nxt=(i+1)%m;
            if(go1[i]<INF/2&&dp1[nxt]<INF/2) dp1[i]=min(dp1[i],go1[i]+dp1[nxt]);
        }
    }
    vector<ld>dp2=direct;
    for(int t=0;t<2;t++){
        for(int i=0;i<m;i++){
            int pre=(i-1+m)%m;
            if(go2[i]<INF/2&&dp2[pre]<INF/2) dp2[i]=min(dp2[i],go2[i]+dp2[pre]);
        }
    }
    vector<ld>dp(m);
    for(int i=0;i<m;i++) dp[i]=min(dp1[i],dp2[i]);
    int bottom=0,top=0;
    for(int i=1;i<m;i++){
        if(h[i].y<h[bottom].y) bottom=i;
        if(h[i].y>h[top].y) top=i;
    }
    i128 mn=(i128)v*h[0].x+(i128)u*h[0].y;
    i128 mx=mn;
    for(int i=1;i<m;i++){
        i128 z=(i128)v*h[i].x+(i128)u*h[i].y;
        mn=min(mn,z);
        mx=max(mx,z);
    }
    auto side=[&](int id,ll s)->i128{
        int nxt=(id+1)%m;
        ll dx=h[nxt].x-h[id].x;
        ll dy=h[nxt].y-h[id].y;
        return cross(dx,dy,s-h[id].x,-h[id].y);
    };
    auto get=[&](ll s)->pair<int,int>{
        int preBottom=(bottom-1+m)%m;
        int good;
        if(side(bottom,s)<=0) good=bottom;
        else good=preBottom;
        int preTop=(top-1+m)%m;
        int bad;
        if(side(top,s)>0) bad=top;
        else bad=preTop;
        int d1=(bad-good+m)%m;
        int l=1,r=d1;
        while(l<r){
            int mid=(l+r)/2;
            int id=(good+mid)%m;
            if(side(id,s)<=0) l=mid+1;
            else r=mid;
        }
        int a=(good+l)%m;
        int d2=(good-bad+m)%m;
        l=1;
        r=d2;
        while(l<r){
            int mid=(l+r)/2;
            int id=(good-mid)%m;
            if(id<0) id+=m;
            if(side(id,s)<=0) l=mid+1;
            else r=mid;
        }
        int id=(good-l)%m;
        if(id<0) id+=m;
        int b=(id+1)%m;
        return {a,b};
    };
    int q;
    cin>>q;
    while(q--){
        ll s;
        cin>>s;
        i128 z=(i128)v*s;
        if(z<=mn||z>=mx){
            cout<<(ld)w/(ld)v<<"\n";
            continue;
        }
        auto [a,b]=get(s);
        ld ans=INF;
        ld x=dis(h[a].x-s,h[a].y);
        if(x<INF/2&&dp[a]<INF/2) ans=min(ans,x+dp[a]);
        if(a!=b){
            ld y=dis(h[b].x-s,h[b].y);
            if(y<INF/2&&dp[b]<INF/2) ans=min(ans,y+dp[b]);
        }
        cout<<ans<<"\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout<<fixed<<setprecision(12);
    int T=1;
    cin>>T;
    while(T--) test();
    return 0;
}