#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pr = pair<ll,ll>;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 2000005;          // 辅助点最多约 1.85e6

struct Opr {
    ll u1, v1, u2, v2, w;
};

ll n, m, s;
ll sf[50010], grandfa[50010][20], exnode[50010][20][2], dep[50010], lg2[1000010], cnt;
ll dis[MAXN];
bool vis[50010], done[MAXN];
vector<pr> edge[MAXN];
queue<Opr> q;
priority_queue<pr, vector<pr>, greater<pr>> pq;   // 小根堆

ll find(ll x) {
    if (sf[x] != x) sf[x] = find(sf[x]);
    return sf[x];
}
void merge(ll x, ll y) {
    ll fx = find(x), fy = find(y);
    if (fx != fy) sf[fx] = fy;
}

void input() {
    cin >> n >> m >> s;
    for (ll i = 1; i <= n; i++) sf[i] = i;        // 并查集初始化！
    for (ll i = 1; i <= m; i++) {
        ll op; cin >> op;
        if (op == 1) {
            ll u1, v1, u2, v2, w;
            cin >> u1 >> v1 >> u2 >> v2 >> w;
            if (find(u1) == find(v1) && find(u2) == find(v2)) {
                q.push({u1, v1, u2, v2, w});
            }
        } else {
            ll u, v, w; cin >> u >> v >> w;
            if (find(u) != find(v)) {
                edge[u].push_back({w, v});
                edge[v].push_back({w, u});
                merge(u, v);
            }
        }
    }
}

void dfs(ll node, ll fa, ll depth) {
    vis[node] = 1;
    grandfa[node][0] = fa;
    dep[node] = depth;
    for (auto i : edge[node]) {
        if (i.second != fa) {
            dfs(i.second, node, depth + 1);
        }
    }
}

void init() {
    cnt = n;
    for (ll i = 2; i <= 1000000; i++) lg2[i] = lg2[i / 2] + 1;
    for (ll i = 1; i <= n; i++) {
        if (!vis[i]) dfs(i, 0, 0);
    }
    for (ll i = 1; i <= n; i++) {
        exnode[i][0][0] = ++cnt;                  // in
        exnode[i][0][1] = ++cnt;                  // out
        edge[exnode[i][0][0]].push_back({i, 0});  // in -> i
        edge[i].push_back({0, exnode[i][0][1]});  // i -> out
    }
    for (ll i = 1; i <= 17; i++) {
        for (ll j = 1; j <= n; j++) {
            grandfa[j][i] = grandfa[grandfa[j][i - 1]][i - 1];
            exnode[j][i][0] = ++cnt;
            exnode[j][i][1] = ++cnt;
            edge[exnode[j][i][0]].push_back({0, exnode[j][i - 1][0]});
            edge[exnode[j][i][0]].push_back({0, exnode[grandfa[j][i - 1]][i - 1][0]});
            edge[exnode[j][i - 1][1]].push_back({0, exnode[j][i][1]});
            edge[exnode[grandfa[j][i - 1]][i - 1][1]].push_back({0, exnode[j][i][1]});
        }
    }
}

ll lca(ll u, ll v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (ll i = 17; i >= 0; i--) {
        if (dep[grandfa[u][i]] >= dep[v]) u = grandfa[u][i];
    }
    if (u == v) return u;
    for (ll i = 17; i >= 0; i--) {
        if (grandfa[u][i] != grandfa[v][i]) {
            u = grandfa[u][i];
            v = grandfa[v][i];
        }
    }
    return grandfa[u][0];
}

void build(){
    while(!q.empty()){
        Opr ask=q.front();
        q.pop();
        ll u1=ask.u1, v1=ask.v1, u2=ask.u2, v2=ask.v2, w=ask.w;
        ll lca1=lca(u1,v1), lca2=lca(u2,v2);
        vector<ll> outnodes, innodes;

        // 分解 u1 到 lca1
        ll cur = u1;
        ll len = dep[u1] - dep[lca1] + 1;
        while(len > 0){
            ll k = lg2[len];
            outnodes.push_back(exnode[cur][k][1]);
            cur = grandfa[cur][k];
            len -= (1 << k);
        }
        // 分解 v1 到 lca1
        cur = v1;
        len = dep[v1] - dep[lca1] + 1;
        while(len > 0){
            ll k = lg2[len];
            outnodes.push_back(exnode[cur][k][1]);
            cur = grandfa[cur][k];
            len -= (1 << k);
        }
        // 分解 u2 到 lca2
        cur = u2;
        len = dep[u2] - dep[lca2] + 1;
        while(len > 0){
            ll k = lg2[len];
            innodes.push_back(exnode[cur][k][0]);
            cur = grandfa[cur][k];
            len -= (1 << k);
        }
        // 分解 v2 到 lca2
        cur = v2;
        len = dep[v2] - dep[lca2] + 1;
        while(len > 0){
            ll k = lg2[len];
            innodes.push_back(exnode[cur][k][0]);
            cur = grandfa[cur][k];
            len -= (1 << k);
        }

        // 连接：起点的 out 节点 -> 终点的 in 节点
        for(ll o : outnodes){
            for(ll i : innodes){
                edge[o].push_back(make_pair(w, i));
            }
        }
    }
}

void dijk() {
    for (ll i = 1; i <= cnt; i++) dis[i] = inf;   // 初始化
    dis[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        while (!pq.empty() && done[pq.top().second]) pq.pop();
        if (pq.empty()) break;
        ll now = pq.top().second; pq.pop();
        done[now] = 1;
        for (auto i : edge[now]) {
            if (done[i.second]) continue;
            if (dis[i.second] > dis[now] + i.first) {
                dis[i.second] = dis[now] + i.first;
                pq.push({dis[i.second], i.second});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    input();
    init();
    build();
    dijk();
    for (ll i = 1; i <= n; i++) {
        if (dis[i] >= inf / 2) cout << -1 << " ";
        else cout << dis[i] << " ";
    }
    return 0;
}