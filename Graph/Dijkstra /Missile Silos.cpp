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

    node(int _idx, ll _cost) : idx(_idx), cost(_cost) {}

    node() {}
};

struct cmp {
    bool operator()(node &a, node &b) {
        return a.cost > b.cost;
    }
};

vector<node> adj[N];
ll n, m, s, l, ans;
ll dist[N];


void Dij() {
    for (int i = 1; i <= n; i++) dist[i] = oo;
    priority_queue<node, vector<node>, cmp> pq;

    pq.push(node(s, 0));
    dist[s] = 0;

    while (sz(pq)) {
        node p = pq.top();
        pq.pop();

        if (dist[p.idx] < p.cost)continue;

        for (auto ch: adj[p.idx]) {
            ll n_cost = ch.cost + p.cost;
            if (dist[ch.idx] > n_cost) {
                dist[ch.idx] = n_cost;
                pq.push(node(ch.idx, n_cost));
            }
        }
    }
}

void clear() {
    ans = 0;
    for (int i = 1; i <= n; i++)
        adj[i].clear();
}

void solve() {
    cin >> n >> m >> s;
    clear();

    vector<array<int, (3)>> edg(m);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edg[i] = {u, v, w};
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    cin >> l;

    Dij();

    for (int i = 1; i <= n; i++)
        if (dist[i] == l) ans++;


    for (auto [u, v, w]: edg) {
        ll du = l - dist[u], cost = w - du;
        if (du > 0 and du < w and l < dist[v] + cost)
            ans++;

        du = l - dist[v], cost = w - du;

        if (du > 0 and du < w and l <= dist[u] + cost)
            ans++;
    }
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
//    cin >> t;
    while (t--) solve();
    return 0;
}
