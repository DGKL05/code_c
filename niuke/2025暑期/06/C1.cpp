#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 998244353;

int main() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    // 预处理逆元
    vector<long long> inv(n + 1);
    inv[1] = 1;
    for (int i = 2; i <= n; i++) {
        inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
    }

    // 计算调和数 H_n, 二次调和数 H2, 三次调和数 H3
    long long H = 0, H2 = 0, H3 = 0;
    for (int k = 1; k <= n; k++) {
        H = (H + inv[k]) % MOD;
        H2 = (H2 + inv[k] * inv[k]) % MOD;
        H3 = (H3 + inv[k] * inv[k] % MOD * inv[k]) % MOD;
    }

    // 计算阶乘 n!
    vector<long long> fact(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    // 计算各项
    long long term1 = H;
    long long term2 = 3 * ((H * H % MOD - H2 + MOD) % MOD) % MOD;
    long long term3 = (H * H % MOD * H % MOD - 3 * H % MOD * H2 % MOD + 2 * H3 % MOD) % MOD;
    term3 = (term3 + MOD) % MOD;  // 确保非负
    long long total = (term1 + term2 + term3) % MOD;

    // 最终结果
    long long result = fact[n] * total % MOD;
    cout << result << endl;

    return 0;
}