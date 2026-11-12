#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll m;
    cin >> n >> m;

    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    sort(a.begin() + 1, a.end());

    int l = 1;
    int ans = 0;
    ll cost = 0; // 当前窗口 [l, r] 全部变成 a[r] 的花费

    for (int r = 1; r <= n; ++r) {
        if (r > 1) {
            // 目标值从 a[r-1] 提高到 a[r]
            cost += 1LL * (r - l) * (a[r] - a[r - 1]);
        }

        // 花费超过 m，则移动左端点
        while (cost > m) {
            cost -= (a[r] - a[l]);
            ++l;
        }

        ans = max(ans, r - l + 1);
    }

    cout << ans << '\n';
    return 0;
}