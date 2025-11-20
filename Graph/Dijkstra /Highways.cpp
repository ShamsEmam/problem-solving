#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(s) s.begin(), s.end()
#define sz(s) (int)(s).size()
int const N = 1e5 + 5;
bool vis[N];
int n, m;
int st, ed;

struct node {
    int idx, cost;
    node(int _idx, int _cost) {
        idx = _idx;
        cost = _cost;
    }
    node() {}
};

vector<node> adj[N];

struct cmp {
    bool operator()(node &a, node &b) {
        return a.cost > b.cost;
    }
};

int Dijkstra(int s, int d) {
    priority_queue<node, vector<node>, cmp> pq;
    pq.push({s, 0});

    while (!pq.empty()) {
        node p = pq.top();
        pq.pop();

        if (p.idx == d)
            return p.cost;
        if (vis[p.idx])continue;
        vis[p.idx] = true;
        for (auto ch: adj[p.idx]) {
            if (!vis[ch.idx]) {
                pq.push(node(ch.idx, p.cost + ch.cost));
            }
        }
    }
    return -1;
}

void clear() {
    memset(vis, false, sizeof vis);
    for (int i = 1; i <= n; ++i) {
        adj[i].clear();
    }
}

void solve() {
    cin >> n >> m;
    cin >> st >> ed;
    clear();
    int u, v, cost;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> cost;
        adj[u].push_back({v, cost});
        adj[v].push_back({u, cost});
    }
    int ans = Dijkstra(st, ed);
    if (ans == -1)
        cout << "NONE\n";
    else
        cout << ans << '\n';
}

void speed() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void setupIO() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}

int main() {
    setupIO();
    speed();
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
