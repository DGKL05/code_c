#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e9+5;
int a[N];int b[N];int c[N];
void test() {
    int n=0;int x,y,z;
    cin>>n>>x>>y>>z;
    for(int i=0;i<n;i++){
        int x1,x2,y1,y2,z1,z2;
        cin>>x1>>y1>>z1>>x2>>y2>>z2;
        a[x1]++;a[x2+1]--;
        b[y1]++;b[y2+1]--;
        c[z1]++;c[z2+1]--;
    }
    int num=0;
    for(int i=1;i<=N;i++){
        a[i]+=a[i-1];
        b[i]+=b[i-1];
        c[i]+=c[i-1];
    }
    for(int i=0;i<=N;i++){
        num=max(num,a[i]);
        num=max(num,b[i]);
        num=max(num,c[i]);
    }
    cout<<num<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    test();
    return 0;
}