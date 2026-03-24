#include<bits/stdc++.h>
using namespace std;
using ll =long long;
using ull =unsigned long long;
void test()
{
    ull n;
    cin >> n;
    ull s = 1;
    while (s <= n) {
        s <<= 1; 
    }
    ull x = s * n;
    ull y = (s + 1) * n;
    cout << x << " " << y << "\n";
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