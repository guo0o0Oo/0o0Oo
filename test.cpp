#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const int N = 1e5 + 10;
int n, m;
int fa[N][20];
int lg[N];
int find(int x, int k) {
    if (x != fa[x][k]) fa[x][k] = find(fa[x][k], k);
    return fa[x][k];
}
void merge(int x, int y, int k) {
    int fx = find(x, k), fy = find(y, k);
    if (fx != fy) fa[fx][k] = fy;
}
ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;
    for (int k = 0; k < 20; k++) {
        for (int i = 1; i + (1 << k) - 1 <= n; i++) {
            fa[i][k] = i;
        }
    }
    for (int i = 1; i <= m; i++) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        int len = r1 - l1 + 1;
        for (int k = lg[len]; k >= 0; k--) {
            if (len >= (1 << k)) {
                merge(l1, l2, k);
                l1 += (1 << k);
                l2 += (1 << k);
                len -= (1 << k);
            }
        }
    }
    for (int k = 19; k >= 1; k--) {
        for (int i = 1; i + (1 << k) - 1 <= n; i++) {
            int p = find(i, k);
            merge(i, p, k - 1);
            merge(i + (1 << (k - 1)), p + (1 << (k - 1)), k - 1);
        }
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (find(i, 0) == i) sum++;
    }
    ll ans = 9 * qpow(10, sum - 1) % MOD;
    cout << ans << "\n";
    return 0;
}