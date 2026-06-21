#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct ch
{
    ll son[26], ct;
    bool win;
} tree[100010];
ll n, k, cnt;
string s;
void add(ll pos)
{
    if (s.empty())
        return;
    int c = s[0] - 'a';
    if (tree[pos].son[c])
    {
        s.erase(0, 1);
        add(tree[pos].son[c]);
        return;
    }
    tree[pos].son[c] = ++cnt;
    tree[pos].ct++;
    s.erase(0, 1);
    add(tree[pos].son[c]);
    return;
}
void dfs(ll node)
{
    if (tree[node].ct == 0)
    {
        tree[node].win = 0;
        return;
    }
    tree[node].win = 0;
    for (ll i = 0; i < 26; i++)
    {
        int c = tree[node].son[i];
        if (c == 0)
            continue;
        dfs(c);
        if (tree[c].win == 0)
        {
            tree[node].win = 1;
        }
    }
}
void dfs1(ll node)
{
    if (tree[node].ct == 0)
    {
        tree[node].win = 1;
        return;
    }
    tree[node].win = 0;
    for (ll i = 0; i < 26; i++)
    {
        int c = tree[node].son[i];
        if (c == 0)
            continue;
        dfs1(c);
        if (tree[c].win == 0)
        {
            tree[node].win = 1;
        }
    }
}
int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);cout.tie(0);
    cin >> n >> k;
    for (ll i = 1; i <= n; i++)
    {
        cin >> s;
        add(0);
    }
    dfs(0);
    if (tree[0].win == 0)
    {
        cout << "Second" << "\n";
        return 0;
    }
    dfs1(0);
    if (tree[0].win)
    {
        cout << "First" << "\n";
        return 0;
    }
    if (k % 2)
    {
        cout << "First" << "\n";
    }
    else
        cout << "Second" << "\n";
    return 0;
}