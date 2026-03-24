#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;int m=0;int k=0;
    cin >> n >> m >> k;
    vector<int> a(n); 
    vector<int> b(m); 
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    vector<bool> fa(n); 
    map<int, vector<int>> m1;

    string s1;
    cin >> s1;
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++) {
        if (b[0] < a[i]) {
            int l = a[i] - (*(lower_bound(b.begin(), b.end(), a[i]) - 1));
            m1[-l].push_back(i);
            // cout<<-l<<"\n";
        }
        if (b[m-1] > a[i]) {
            int r = *lower_bound(b.begin(), b.end(), a[i]) - a[i];
            m1[r].push_back(i);
            // cout<<r<<"\n";
        }
    }
    int ind = 0;
    int ans = n;
    for (auto &x: s1) {
        if (x == 'L') ind--;
        else ind++;
        for (int i: m1[ind]) {
            if (fa[i]) continue;
            fa[i] = true;
            ans--;
        }
        m1[ind].clear();
        cout << ans << " ";
    }
    cout << "\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}