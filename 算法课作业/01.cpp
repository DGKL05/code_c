#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 0, m = 0;
    cin >> n >> m;
    int chickens = (4 * m - n) / 2;
    int rabbits = m - chickens;
    cout << chickens << " " << rabbits<<"\n";
    return 0;
}