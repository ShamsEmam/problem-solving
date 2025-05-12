#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ld long double

const ld INF = 1e18;
int n, m, p;
vector<pair<int, ld>> adj[55];
ld dista[55][55];
vector<pair<int, ld>> save;
ld dp[(1 << 12) + 10][55];
bool seen[(1 << 12) + 10][55];

void Dijkstra(int src) {
    for (int i = 0; i <= n; ++i) 
       dista[src][i] = INF;
  
    dista[src][src] = 0;
  
    priority_queue<pair<ld, int>> pq;
    pq.push({0, src});
  
    while (!pq.empty()) {
        auto [negd, u] = pq.top();
        pq.pop();
        ld d = -negd;
        if (d > dista[src][u]) 
          continue;
        for (auto &e: adj[u]) {
            int v = e.first;
            ld w = e.second;
            if (d + w < dista[src][v]) {
                dista[src][v] = d + w;
                pq.push({-dista[src][v], v});
            }
        }
    }
}

ld rec(int mask, int u) {
    if (mask == (1 << p) - 1) {
        return -dista[u][0];
    }
    if (seen[mask][u]) return dp[mask][u];
    seen[mask][u] = true;
    ld best = -dista[u][0];
    for (int i = 0; i < p; ++i) {
        if (mask & (1 << i)) continue;
        int store = save[i].first;
        ld saving = save[i].second;
        ld cand = saving - dista[u][store] + rec(mask | (1 << i), store);
        best = max(best, cand);
    }
    return dp[mask][u] = best;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i <= n; ++i) adj[i].clear();
    for (int i = 0; i < m; ++i) {
        int u, v;
        ld w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    cin >> p;
    save.resize(p);
    for (int i = 0; i < p; ++i) {
        int store;
        ld saving;
        cin >> store >> saving;
        save[i] = {store, saving};
    }
    for (int i = 0; i <= n; ++i) {
        Dijkstra(i);
    }
    memset(seen, 0, sizeof(seen));
    ld ans = rec(0, 0);

    if (ans > 1e-8) {
        cout << "Daniel can save $";
        cout << fixed << setprecision(2) << ans << '\n';
    } else {
        cout << "Don't leave the house\n";
    }
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

signed main() {
    setupIO();
    speed();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
