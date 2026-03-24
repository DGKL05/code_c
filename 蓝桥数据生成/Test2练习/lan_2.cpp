#include <bits/stdc++.h>
using namespace std;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    string a, b;
    cin >> a >> b;

    int ans = 0;
    int lst = -1, state = -1;
    // lst 就是文中的 lst
    // state 则代表 lst 对应的情况，对应文中的 1 2 3 三种
    for(int i = 0; i < a.size(); i++) {
        if(a[i] == '.' && b[i] == '.') continue;
        if(lst != -1) {
            ans += i - lst - 1;
        }
        if(a[i] == '#' && b[i] == '#') {
            state = 3;
        } else if(a[i] == '#' && b[i] == '.') {
            if(state == 2) {
                ans++;
                state = 3;
            } else {
                state = 1;
            }
        } else if(a[i] == '.' && b[i] == '#') {
            if(state == 1) {
                ans++;
                state = 3;
            } else {
                state = 2;
            }
        }
        lst = i;
    }
    cout << ans << endl;
    return 0;
}