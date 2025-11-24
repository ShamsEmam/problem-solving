#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(s) s.begin(), s.end()
#define sz(s) (int)(s).size()
int const N = 2e5+5, inf = 1e15;
ll n, m;

struct node {
    ll idx, cost;

    node(ll _idx, ll _cost) : idx(_idx), cost(_cost) {}

    node() {}
};

struct cmp {
    bool operator()(node &a, node &b) {
        return a.cost > b.cost;
    }
};

vector<node> adj[N];
vector<ll> a;
ll dist[N];

void dij() {
    priority_queue<node, vector<node>, cmp> pq;
    for (int i = 1; i <= n; ++i) {
        pq.push({i, a[i]});
        dist[i] = a[i];
    }

    while (!pq.empty()) {
        node p = pq.top();
        pq.pop();

        if (p.cost > dist[p.idx])continue;

        for (auto ch: adj[p.idx]) {
            ll new_cost = 2 * ch.cost + p.cost;

            if (new_cost < dist[ch.idx]) {
                dist[ch.idx] = new_cost;
                pq.push({ch.idx, new_cost});
            }
        }
    }
}

void clear() {
    for (int i = 1; i <= n; i++)
        adj[i].clear();
}

void solve() {
    cin >> n >> m;
    ll u, v, cost;
    a.resize(n + 1);
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> cost;
        adj[u].emplace_back(v, cost);
        adj[v].emplace_back(u, cost);
    }
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    dij();
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << ' ';
    }
    clear();
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
