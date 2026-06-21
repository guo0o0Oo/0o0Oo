#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 1e5 + 10;
ll n, s, f;
ll a[MAXN]; // 每个时区的人数
ll diff[MAXN * 2 + 10]; // 差分数组，需要开大一点以处理循环

// 辅助函数，将0或负数模n的结果转换为正数
ll mod_n(ll x) {
    return ((x - 1) % n + n) % n + 1; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> s >> f;

    // 对于每个时区 j，计算其有效比赛开始时间区间 [l, r]
    for (int j = 1; j <= n; j++) {
        // 当地时间 s 对应的开始时间 i_start = (s - j + 1 + n) % n
        // 如果余数为0，说明 i_start 应该是 n
        ll l = mod_n(s - j + 1);
        
        // 当地时间 f-1 (因为 f 不包含) 对应的开始时间 i_end = (f-1 - j + 1 + n) % n
        ll r = mod_n(f - 1 - j + 1);

        // 如果区间 [l, r] 没有跨越边界 (l <= r)
        if (l <= r) {
            diff[l] += a[j];
            diff[r + 1] -= a[j];
        } else {
            // 如果区间跨越了边界 (l > r)，例如 [8, 2]，实际是 [8,n] U [1,2]
            // 先处理 [l, n]
            diff[l] += a[j];
            diff[n + 1] -= a[j];
            // 再处理 [1, r]
            diff[1] += a[j];
            diff[r + 1] -= a[j];
        }
    }

    // 通过前缀和还原原数组，并找到最大值对应的索引
    ll current_sum = 0;
    ll max_sum = -1;
    ll best_time = 1;

    for (int i = 1; i <= n; i++) {
        current_sum += diff[i];
        if (current_sum > max_sum) {
            max_sum = current_sum;
            best_time = i;
        }
    }

    cout << best_time << "\n";
    return 0;
}