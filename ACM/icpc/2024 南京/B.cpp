#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    string s;
    cin >> s;
    int cnt2 = 0, cnt[2][2]{};
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '2') {
            cnt2++;
        } else {
            cnt[i & 1][s[i] - '0']++;
        }
    }
    int cnt1 = abs(cnt[0][1] - cnt[1][1]);  // 剩下的1
    int cnt0 = abs(cnt[0][0] - cnt[1][0]);  // 剩下的0
    cout<<cnt1<<" "<<cnt0<<"\n";
    int tmp = min(cnt0, cnt2);  // 用2消0
    cnt2 -= tmp;
    cnt0 -= tmp;
    tmp = min(cnt1, cnt2);  // 用2消1
    cnt2 -= tmp;
    cnt1 -= tmp;
    cnt2 %= 2;  // 剩下的2两两互消
    cout << (cnt0 + cnt1 + cnt2) << endl;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}