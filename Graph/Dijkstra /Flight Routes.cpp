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
ll n, m, k;
vector<vector<ll>> dist;

void Dij() {
    dist.assign(n + 1, vector<ll>());
    priority_queue<node, vector<node>, cmp> pq;
    pq.push({1, 0});
    dist[1].push_back(0);


    while (sz(pq)) {
        node p = pq.top();
        pq.pop();


        for (auto ch: adj[p.idx]) {
            ll n_cost = p.cost + ch.cost;

            if (sz(dist[ch.idx]) < k) {
                dist[ch.idx].push_back(n_cost);
                sort(all(dist[ch.idx]));
                pq.push(node(ch.idx, n_cost));
            } else if (dist[ch.idx].back() > n_cost) {

                dist[ch.idx].pop_back();
                dist[ch.idx].push_back(n_cost);
                sort(all(dist[ch.idx]));
                pq.push(node(ch.idx, n_cost));
            }
        }
    }
}

void solve() {
    cin >> n >> m >> k;
    int u, v, w;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
    }
    Dij();
    sort(all(dist[n]));
    ll sz = min(sz(dist[n]), k);
    for (int i = 0; i < sz; ++i) {
        cout << dist[n][i] << ' ';
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

int main() {
    setupIO();
    speed();
    int t = 1;

    while (t--) solve();
    return 0;
}
