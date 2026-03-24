#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int a=0;int b=0;
    cin >> a >> b;
    if (b == 0) {
        for(int i=0;i<a;i++) cout<<"0";
        cout<<"\n";
        return ;
    }
    if (a == 0) {
        for(int i=0;i<b;i++) cout<<"1";
        cout<<"\n";
        return ;
    }
    ll k = min(a, b + 1);
    ll t = 0;
    if (k <= b - 1) {
        t = k + 1;
    } else {
        t = b;
    }
    ll r0 = a % k;
    ll r1 = b % t;
    string ans;
    ans.resize(a + b);
    if (t == k + 1) {
        for (int i = 0; i < t; i++) {
            ans.append((b / t) + (i < r1 ? 1 : 0), '1');
            if (i < k) {
                ans.append((a / k) + (i < r0 ? 1 : 0), '0');
            }
        }
    } else if (t == k) {
        for (int i = 0; i < k; i++) {
            ans.append((a / k) + (i < r0 ? 1 : 0), '0');
            if (i < t) {
                ans.append((b / t) + (i < r1 ? 1 : 0), '1');
            }
        }
    } else if (t == k - 1) {
        for (int i = 0; i < k; i++) {
            ans.append((a / k) + (i < r0 ? 1 : 0), '0');
            if (i < t) {
                ans.append((b / t) + (i < r1 ? 1 : 0), '1');
            }
        }
    }
    cout<< ans <<"\n";
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