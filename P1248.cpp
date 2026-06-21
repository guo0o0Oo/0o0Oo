#include<bits/stdc++.h>

using namespace std;

int n, ans[10001];

struct node {
    int a, b, m, num;
} train[10001];

bool cmp(node x, node y) { return x.m < y.m; }

void read() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &train[i].a);
    for (int i = 1; i <= n; i++) scanf("%d", &train[i].b);
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

    int t1 = 0, t2 = 0;
	for (int i = 1; i <= n; i++) { 
		t1 += train[ans[i]].a;
		if (t2 < t1)t2 = t1;
		t2 += train[ans[i]].b;
	}
	printf("%d\n", t2);
	for (int i = 1; i <= n; i++) printf("%d ", train[ans[i]].num);
}

int main() {
    read();
    solve();
    return 0;
}
