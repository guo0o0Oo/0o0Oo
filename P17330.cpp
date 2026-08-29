#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Z算法：返回z数组，z[i]表示s和s[i..]的最长公共前缀长度
vector<int> z_algorithm(const string& s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i <= r) z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

// Manacher算法：返回奇数半径和偶数半径
// 半径定义为包含中心的最长回文长度的一半（向上取整）
pair<vector<int>, vector<int>> manacher(const string& s) {
    int n = s.size();
    vector<int> d1(n), d2(n);
    
    // 奇数长度回文
    int l = 0, r = -1;
    for (int i = 0; i < n; i++) {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
        while (i - k >= 0 && i + k < n && s[i - k] == s[i + k]) k++;
        d1[i] = k;
        if (i + k - 1 > r) {
            l = i - k + 1;
            r = i + k - 1;
        }
    }
    
    // 偶数长度回文
    l = 0, r = -1;
    for (int i = 0; i < n; i++) {
        int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
        while (i - k - 1 >= 0 && i + k < n && s[i - k - 1] == s[i + k]) k++;
        d2[i] = k;
        if (i + k - 1 > r) {
            l = i - k;
            r = i + k - 1;
        }
    }
    
    return {d1, d2};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s, t;
    cin >> s >> t;
    
    int n = s.size(), m = t.size();
    
    // 1. 反转t
    string rt = t;
    reverse(rt.begin(), rt.end());
    
    // 2. Z算法求匹配长度
    string combined = rt + "#" + s;
    vector<int> z = z_algorithm(combined);
    
    vector<int> match_len(n);
    int offset = m + 1; // rt长度 + 分隔符
    for (int i = 0; i < n; i++) {
        match_len[i] = min(z[offset + i], m);
    }
    
    // 3. Manacher求回文半径
    auto [d1, d2] = manacher(s);
    
    // 4. 统计以每个位置为起点的回文子串个数
    vector<int> pal_start(n, 0);
    
    // 处理奇数长度回文
    for (int i = 0; i < n; i++) {
        int radius = d1[i]; // 半径，回文长度为 2*radius-1
        // 起点范围: [i - radius + 1, i]
        int left = i - radius + 1;
        int right = i;
        if (left <= right) {
            pal_start[left]++;
            if (right + 1 < n) pal_start[right + 1]--;
        }
    }
    
    // 处理偶数长度回文
    for (int i = 0; i < n; i++) {
        int radius = d2[i]; // 半径，回文长度为 2*radius
        // 起点范围: [i - radius, i - 1]
        int left = i - radius;
        int right = i - 1;
        if (left <= right) {
            pal_start[left]++;
            if (right + 1 < n) pal_start[right + 1]--;
        }
    }
    
    // 前缀和得到每个起点的回文子串数
    for (int i = 1; i < n; i++) {
        pal_start[i] += pal_start[i - 1];
    }
    
    // 5. 前缀和数组方便区间查询
    vector<ll> pref(n + 1, 0);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + pal_start[i];
    }
    
    // 6. 统计答案
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int len = match_len[i];
        if (len == 0) continue;
        
        // k 从 1 到 len，起点为 i+k
        // 注意 i+k 必须 < n，并且要长度至少为1的回文
        int l = i + 1;      // k=1 时的起点
        int r = min(i + len, n - 1); // 最大可能的起点
        
        if (l <= r) {
            ans += pref[r + 1] - pref[l];
        }
    }
    
    cout << ans << '\n';
    
    return 0;
}