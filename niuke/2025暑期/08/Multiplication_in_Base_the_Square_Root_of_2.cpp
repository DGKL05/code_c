#include<bits/stdc++.h>
using namespace std;
using LL =long long;
int n;int m;
const LL N = 1e6 + 10, M = 3e4 + 10, INF64 = 1e18 + 10, base = 2e4, P = 131, mod = 1e18 + 7;
const double PI = acos(-1.0);
 
void FFT(vector<complex<double>>& a, int invert) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        while (j & bit) {
            j ^= bit;
            bit >>= 1;
        }
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }
 
    for (int len = 2; len <= n; len <<= 1) {
        double angle = 2 * PI / len * (invert ? -1 : 1);
        complex<double> wlen(cos(angle), sin(angle));
        for (int i = 0; i < n; i += len) {
            complex<double> w(1);
            for (int j = 0; j < len / 2; ++j) {
                complex<double> u = a[i + j];
                complex<double> v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }
 
    if (invert) {
        for (auto& x : a) x /= n;
    }
}
 
vector<int> mul(const vector<int>& a, const vector<int>& b) {
    vector<complex<double>> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) n <<= 1;
    fa.resize(n);
    fb.resize(n);
 
    FFT(fa, false);
    FFT(fb, false);//op == 0 求点值
    for (int i = 0; i < n; ++i) fa[i] *= fb[i];
    FFT(fa, true);//op == 1 逆变换求系数
 
    vector<int> res(n);
    for (int i = 0; i < n; ++i) res[i] = round(fa[i].real());
    return res;
}
 
vector<int>g[N];

// 将二进制字符串转换为多项式系数
vector<int> binary_to_polynomial(const string& binary) {
    vector<int> poly;
    // 反转二进制字符串，使最低位对应x^0
    for (auto it = binary.rbegin(); it != binary.rend(); ++it) {
        poly.push_back(*it - '0');
    }
    return poly;
}
 
vector<int> cal(const string& a, const string& b) {
    vector<int> polya = binary_to_polynomial(a);
 
    vector<int> polyb = binary_to_polynomial(b);
    vector<int> res = mul(polya, polyb);
    return res;
}

void test()
{
    string a, b;
    cin >> a >> b;
    n = a.length();
    m = b.length();
    auto res = cal(a, b);
    //for (auto x : res) {
    //    cout << x << " ";
    //}
    //cout << endl;
    unordered_map<LL, LL>d;
    for (int i = 0; i < n + m; i++) {
        int x = res[i];
        //cout << "i = " << i << " x = " << x << endl;
        for (int j = 0; j <= 20; j++) {
            if (x >> j & 1) {
                if (j & 1) {
                    LL val = j * 2;
                    d[val + i]++;
                    val = (j + 1) * 2;
                    d[val + i]++;
                }
                else {
                    LL val = j * 2;
                    d[val + i]++;
                }
            }
        }
    }
    //cout << "dddddddd" << endl;
    //for (auto [f,s] : d) {
    //    cout << f << " " << s << endl;
    //}
    vector<int>str;
    for (int i = 0; i <= n + m + 100; i++) {
        if (d[i] > 0) {
            d[i + 2] -= d[i] / 2;
            d[i] %= 2;
        }
        if (d[i] < 0) {
            d[i] = abs(d[i]);
            d[i + 2] += (d[i] + 1) / 2;
            d[i] %= 2;
        }
        if (d[i]) {
            str.push_back(1);
        }
        else str.push_back(0);
    }
    while (!str.empty() && str.back() == 0) {
        str.pop_back();
    }
    if (str.empty()) {
        cout << 0 << endl;
        return;
    }
    //cout << "str.size() = " << str.size() << endl;
    reverse(str.begin(), str.end());
    for (int i = 0; i < str.size(); i++) {
        cout << str[i];
    }
    cout << '\n';
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}