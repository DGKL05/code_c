#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    string s;
    cin >> s;
    int n = s.size();
    int count = 0;
    bool fa = false;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            count++;
        } else {
            count--;
        }
        if (count == 0) {
            if (i != n - 1) {
                cout << "YES\n";
                fa = true;
                break;
            } else {
                // 第一个闭合位置在末尾，后续无需继续遍历
                break;
            }
        }
    }
    if (!fa) {
        cout << "NO\n";
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}
