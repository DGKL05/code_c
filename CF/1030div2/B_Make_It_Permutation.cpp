#include<bits/stdc++.h>
using namespace std;
using ll =long long;
/*
1 5 4 3 2
2 1 5 4 3
3 2 1 5 4
4 3 2 1 5
5 4 3 2 1
*/
void test()
{
    int n=0;
    cin >> n;
    int k = 2 * n - 3;
    cout << k << "\n";
    for (int i = 1; i <= n; i++) {
        if (i >= 2) {
            cout << i << " " << 1 << " " << i << "\n";
        }
        if (n - i >= 2) {
            cout << i << " " << i + 1 << " " << n << "\n";
        }
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