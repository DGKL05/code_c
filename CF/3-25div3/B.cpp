#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int &num : a) {
        cin >> num;
    }
    sort(a.rbegin(), a.rend()); // 降序排序

    int cnt = 0, ans = 0;
    for (int num : a) {
        cnt++;
        if (num * cnt >= x) {
            ans++;
            cnt = 0;
        }
    }
    cout << ans << '\n';
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);//std::cout.tie(0);
    int t=0;
    cin>>t;
    while(t--) test();
    return 0;
}