#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const ld INF = 1e100;
const ld eps = 1e-15;

void test(){
    ld w,x1,x2,yc,u,v;
    cin>>w>>x1>>x2>>yc>>u>>v;

    ld t0 = yc/v;

    ld l = x1+u*t0;
    ld r = x2+u*t0;

    if(l >= 0 || r <= 0){
        cout<<fixed<<setprecision(10)<<w/v<<"\n";
        return;
    }

    auto calc = [&](ld x){
        ld A = u*u-v*v;
        ld B = 2*x*u;
        ld C = x*x+yc*yc;

        auto f = [&](ld t){
            return A*t*t+B*t+C;
        };

        if(f(t0) <= 0){
            return t0;
        }

        if(fabsl(A) < eps){
            if(B >= 0){
                return INF;
            }

            ld t = -C/B;

            if(t >= t0) return t;
            return INF;
        }

        ld D = B*B-4*A*C;

        if(D < 0){
            return INF;
        }

        D = max((ld)0,D);

        ld sq = sqrtl(D);

        ld t1 = (-B-sq)/(2*A);
        ld t2 = (-B+sq)/(2*A);

        if(t1 > t2) swap(t1,t2);

        if(A < 0){
            if(t2 >= t0) return t2;
        }else{
            if(t1 >= t0) return t1;
        }

        return INF;
    };

    ld t1 = calc(x1);
    ld t2 = calc(x2);

    ld t = min(t1,t2);

    ld ans = t+(w-yc)/v;

    cout<<fixed<<setprecision(10)<<ans<<"\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T = 1;
    cin>>T;

    while(T--) test();

    return 0;
}