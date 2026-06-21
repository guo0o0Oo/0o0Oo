#include<bits/stdc++.h>

using namespace std;

using ll = long long;

ll n, ans[20001];

struct node {
    ll a, b, m, num;
} train[20001];

bool cmp(node x, node y) { return x.m < y.m; }

void read() {
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) scanf("%lld %lld", &train[i].a, &train[i].b);
}

void solve() {
    for (int i = 1; i <= n; i++) {
        train[i].m = min(train[i].a, train[i].b);
        train[i].num = i;
    }

    sort(train + 1, train + n + 1, cmp);

    int k = 0, t = n + 1;
    for (int i = 1; i <= n; i++) {
        if (train[i].m == train[i].a) {
            ++k;
            ans[k] = i;
        } else {
            --t;
            ans[t] = i;
        }
    }

	ll pre = 0, s = 0, maxc = 0;
	for (int i = 1; i <= n; i++) {
		s += train[ans[i]].a;
		pre = max (s, pre) + train[ans[i]].b;
		maxc = max (maxc, pre);
	}
	printf("%lld\n", maxc);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
	    read();
	    solve();
	}
    return 0;
}
