#include <bits/stdc++.h>

using namespace std;

constexpr int N = 2*1e6+10;

string s;
int n;
int m, p, rk[N * 2], oldrk[N], sa[N * 2], id[N], cnt[N];

int main() {
    cin>>n;
    s+=' ';
    for(int i=0;i<n;i++){
        char a;
        cin>>a;
        s+=a;
    }
    for(int i=n;i>0;i--){
        s+=s[i];
    }
    n*=2;
    m = 128;

    for (int i = 1; i <= n; i++) cnt[rk[i] = s[i]]++;
    for (int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
    for (int i = n; i >= 1; i--) sa[cnt[rk[i]]--] = i;

    for (int w = 1;; w <<= 1, m = p) {  // m = p 即为值域优化
        int cur = 0;
        for (int i = n - w + 1; i <= n; i++) id[++cur] = i;
        for (int i = 1; i <= n; i++)
        if (sa[i] > w) id[++cur] = sa[i] - w;

        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; i++) cnt[rk[i]]++;
        for (int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
        for (int i = n; i >= 1; i--) sa[cnt[rk[id[i]]]--] = id[i];

        p = 0;
        memcpy(oldrk, rk, sizeof(oldrk));
        for (int i = 1; i <= n; i++) {
        if (oldrk[sa[i]] == oldrk[sa[i - 1]] &&
            oldrk[sa[i] + w] == oldrk[sa[i - 1] + w])
            rk[sa[i]] = p;
        else
            rk[sa[i]] = ++p;
        }

        if (p == n) break;  // p = n 时无需再排序
    }
    string ans;
    int i=1;int j=n/2+1;int num=0;
    while(num!=(n/2)){
        if(rk[i]<rk[j]){
            ans+=s[i];
            i++;
        }else{
            ans+=s[j];
            j++;
        }
        num++;
    }
    n/=2;
    for(int i=0;i<n;i++){
        cout<<ans[i];
        if((i+1)%80==0) cout<<"\n";
    }
    return 0;
}