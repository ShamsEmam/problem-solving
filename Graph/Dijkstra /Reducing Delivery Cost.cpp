#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(s) s.begin(), s.end()
#define sz(s) (ll)(s).size()

const int N = 2e5 + 5;
const ll oo = 1e15;

struct node {
    int idx;
    ll cost;
    bool used;

    node(int _x, ll _cost) : idx(_x), cost(_cost) {}

    node() {}
};

struct cmp {
    bool operator()(node &a, node &b) {
        return a.cost > b.cost;
    }
};

vector<node> adj[N];
ll n, m, k;
//ll dist[N];
vector<vector<ll>> dist;

void Dij() {
    dist.assign(n + 1, vector<ll>(n + 1, oo));


    for (int src = 1; src <= n; src++) {
        priority_queue<node, vector<node>, cmp> pq;

        pq.push(node(src, 0));
        dist[src][src] = 0;

        while (sz(pq)) {
            node p = pq.top();
            pq.pop();

            if (dist[src][p.idx] != p.cost)continue;

            for (auto ch: adj[p.idx]) {
                ll n_cost = ch.cost + p.cost;
                if (dist[src][ch.idx] > n_cost) {
                    dist[src][ch.idx] = n_cost;
                    pq.push(node(ch.idx, n_cost));
                }
            }
        }
    }
}

void clear() {
    for (int i = 1; i <= n; i++)
        adj[i].clear();
}

void solve() {
    cin >> n >> m >> k;
    clear();

    int U, V, W;
    vector<array<int, 3>> edg(m);
    for (int i = 0; i < m; ++i) {
        cin >> U >> V >> W;
        edg[i] = {U, V, W};
        adj[U].emplace_back(V, W);
        adj[V].emplace_back(U, W);
    }
    vector<pair<ll, ll>> query(k);
    for (int i = 0; i < k; i++) {
        cin >> query[i].first >> query[i].second;
    }
    Dij();
    ll ans = 0ll;
    for (auto [a, b]: query) {
        ans += dist[a][b];
    }
    for (auto [u, v, w]: edg) {
        ll cur = 0;
        for (auto [a, b]: query) {
            ll org = dist[a][b];
            ll uv = dist[a][u] + dist[v][b];
            ll vu = dist[a][v] + dist[u][b];
            ll best = min({org, uv, vu});
            cur += best;
        }
        ans = min(ans, cur);
    }
    cout << ans << ' ';
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
//    cin >> t;
    while (t--) solve();
    return 0;
}
