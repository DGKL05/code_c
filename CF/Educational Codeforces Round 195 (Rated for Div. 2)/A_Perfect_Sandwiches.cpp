#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void test()
{
    int a, b;
    cin >> a >> b;
    if(a <= b){
        cout << -1 << "\n";
        return;
    }
    cout << min(b, a - b) << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) test();

    return 0;
}
