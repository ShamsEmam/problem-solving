#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double

const int N = 8;
const int M = 35;
const ld INF = 1e18;

int n, m, p, a, b;
int ticket[N];
vector<pair<int,int>> adj[M];
ld distState[1 << N][M];

struct State {
    ld cost;
    int city;
    int mask;
    bool operator>(const State& o) const {
        return cost > o.cost;
    }
};

void runMaskDijkstra() {
    int full = 1 << n;
    for (int mask = 0; mask < full; ++mask)
        for (int city = 1; city <= m; ++city)
            distState[mask][city] = INF;

    priority_queue<State, vector<State>, greater<State>> pq;
    distState[0][a] = 0;
    pq.push({0, a, 0});

    while (!pq.empty()) {
        State s = pq.top(); pq.pop();
        if (s.cost > distState[s.mask][s.city]) continue;

        for (int i = 0; i < n; ++i) {
            if ((s.mask >> i) & 1) continue;
            int newMask = s.mask | (1 << i);

            for (auto& [v, w] : adj[s.city]) {
                ld nc = s.cost + (ld)w / ticket[i];
                if (nc < distState[newMask][v]) {
                    distState[newMask][v] = nc;
                    pq.push({nc, v, newMask});
                }
            }
        }
    }
}

void solve() {
    while (cin >> n >> m >> p >> a >> b, n||m||p||a||b) {
        for (int i = 0; i < n; ++i)
            cin >> ticket[i];

        for (int i = 1; i <= m; ++i)
            adj[i].clear();
        for (int i = 0; i < p; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }

        runMaskDijkstra();

        ld ans = INF;
        int full = 1 << n;
        for (int mask = 0; mask < full; ++mask)
            ans = min(ans, distState[mask][b]);

        if (ans >= INF/2)
            cout << "Impossible\n";
        else
            cout << fixed << setprecision(3) << ans << "\n";
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
    int t = 1;
    while (t--) solve();
    return 0;
}
