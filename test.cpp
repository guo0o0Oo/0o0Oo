#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 1e6 + 10;
const int mod = 1e9 + 7;

int n, m, p2[MAXN], sum, ans;
int p[MAXN], w[MAXN], t[MAXN], dp[MAXN];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    p2[0] = 1;
    for (int i = 1; i <= n; i++) {
        p2[i] = p2[i - 1] + p2[i - 1];
        if (p2[i] >= mod) p2[i] -= mod;
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i] >> w[i];
    }

    for (int i = 1, j = 1, k = 0; i <= n; i++) {
        if (w[i]) {
            dp[i] = ans + 1;
            ans += dp[i];
            if (ans >= mod) ans -= mod;
            sum += dp[i];
            if (sum >= mod) sum -= mod;
        } else {
            while (p[j] + m < p[i]) {
                sum -= (ll)dp[j] * p2[k] % mod;
                if (sum < 0) sum += mod;
                k -= t[++j];
            }
            ans += sum;
            if (ans >= mod) ans -= mod;
            sum += sum;
            if (sum >= mod) sum -= mod;
            k++;
            t[i + 1]++;
        }
        cout << dp[i] << " ";
    }

    cout << "\n";
    for (int i = 1; i <= n; i++) {
        cout << dp[i] << " ";
    }
    cout << "\n";
    for (int i = 1; i <= n; i++) {
        cout << t[i] << " ";
    }
    cout << ans;

    return 0;
}