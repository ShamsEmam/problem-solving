#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(s) s.begin(), s.end()
#define sz(s) (int)(s).size()
int const N = 1e6 + 5;
ll oo = 1e15;
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
ll dist[N];

void dij(ll src) {
    priority_queue<node, vector<node>, cmp> pq;
    for (int i = 0; i < n; ++i) {
        dist[i] = oo;
    }
    pq.push({src, 0});
    dist[src] = 0;

    while (!pq.empty()) {
        node p = pq.top();
        pq.pop();

        if (p.cost != dist[p.idx])continue;

        for (auto ch: adj[p.idx]) {
            ll new_cost = ch.cost + p.cost;

            if (new_cost < dist[ch.idx]) {
                dist[ch.idx] = new_cost;

                pq.push({ch.idx, new_cost});
            }
        }
    }
}

void clear() {
    for (int i = 0; i < n; i++)
        adj[i].clear();
}

void solve() {
    int q, x;
    cin >> n >> m >> q;
    ll u, v, cost;

    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> cost;
        adj[u].emplace_back(v, cost);
        adj[v].emplace_back(u, cost);
    }

    while (q--) {
        cin >> x;
        dij(x);
        ll mx = 0;
        ll cnt = 0;

        for (int i = 0; i < n; i++) {
            if (dist[i] == oo) continue;

            if (dist[i] > mx) {
                mx = dist[i];
                cnt = 1;
            } else if (dist[i] == mx) {
                cnt++;
            }
        }

        cout << mx << " " << cnt << "\n";
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
