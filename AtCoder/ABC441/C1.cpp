#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    long long X;
    cin >> N >> K >> X;

    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // 步骤1：升序排序数组
    sort(A.begin(), A.end());

    // 步骤2：计算最小的K个元素的和（选所有杯子时的最坏情况）
    long long sum_min_K = 0;
    for (int i = 0; i < K; ++i) {
        sum_min_K += A[i];
    }
    if (sum_min_K < X) {
        cout << -1 << endl;
        return 0;
    }

    // 步骤3：构建前缀和数组，快速计算区间和（prefix[0]=0, prefix[i]=A[0]+...+A[i-1]）
    vector<long long> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + A[i];
    }

    // 步骤4：二分查找最小的m
    int left = 1, right = N;
    int ans = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2; // 防止溢出
        long long s = max(0LL, (long long)K + mid - N);

        long long current_sum = 0;
        if (s > 0) {
            int l = N - mid; // 最大的mid个元素的起始索引（升序排序后）
            int r = l + s - 1; // 最小的s个元素的结束索引
            current_sum = prefix[r + 1] - prefix[l];
        }

        if (current_sum >= X) {
            ans = mid;
            right = mid - 1; // 尝试寻找更小的m
        } else {
            left = mid + 1; // 需要更大的m
        }
    }

    cout << ans << endl;
    return 0;
}