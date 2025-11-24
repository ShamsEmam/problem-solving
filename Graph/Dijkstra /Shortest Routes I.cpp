#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(s) s.begin(), s.end()
#define sz(s) (int)(s).size()
int const N = 2e5 + 5;
ll const oo = 1e15;
ll dist[N];

struct node {
    int idx;
    ll cost;

    node(int _x1, ll _x2) : idx(_x1), cost(_x2) {}

    node() {}
};

struct cmp {
    bool operator()(node &a, node &b) {
        return a.cost > b.cost;
    }
};

int n, m;
vector<node> adj[N];

void Dij(int src) {
    for (int i = 0; i <= n; i++)
        dist[i] = oo;

    priority_queue<node, vector<node>, cmp> pq;
    pq.push(node(src, 0));
    dist[src] = 0;

    while (sz(pq)) {
        node p = pq.top();
        pq.pop();

        if (p.cost > dist[p.idx])continue;

        for (auto ch: adj[p.idx]) {
            ll new_cost = p.cost + ch.cost;
            if (new_cost < dist[ch.idx]) {
                dist[ch.idx] = new_cost;
                pq.push(node(ch.idx, new_cost));
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
    int u, v, w;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    Dij(1);

    for (int i = 1; i <= n; i++)cout << dist[i] << ' ';
    cout << '\n';
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
