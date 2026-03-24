#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++ i) {
    	std::cin >> a[i];
    }

    int max = *std::max_element(a.begin(), a.end());
    int min = *std::min_element(a.begin(), a.end());
    int cnt = std::ranges::count(a, max);
    ll sum = std::accumulate(a.begin(), a.end(), 0ll);
    if (max - 1 - min > k || (max - min > k && cnt > 1) || sum % 2 == 0) {
    	std::cout << "Jerry\n";
    } else {
    	std::cout << "Tom\n";
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int t=0;
    cin>>t;
    while(t--) test();
    return 0;
}