#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(s) s.begin(), s.end()
#define sz(s) (int)(s).size()

const int N = 2e5 + 5;
const ll oo = 1e15;

struct node {
    int idx;
    ll cost;
    bool used;

    node(int _idx, ll _cost, bool _used) : idx(_idx), cost(_cost), used(_used) {}

    node() {}
};

struct cmp {
    bool operator()(node &a, node &b) {
        return a.cost > b.cost;
    }
};

ll dist[N][2];
vector<node> adj[N];
ll n, m;

ll Dij() {
    for (int i = 0; i <= n; i++)
        dist[i][0] =dist[i][1]= oo;

    priority_queue<node, vector<node>, cmp> pq;
    pq.push({1, 0, 0});
    dist[1][0] = 0;

    while (sz(pq)) {
        node p = pq.top();
        pq.pop();

        if (p.cost > dist[p.idx][p.used])continue;

        for (auto ch: adj[p.idx]) {

            // use copone
            if (dist[p.idx][p.used] + ch.cost < dist[ch.idx][p.used]) {
                ll new_cost = dist[p.idx][p.used] + ch.cost;
                dist[ch.idx][p.used] = new_cost;
                pq.push(node(ch.idx, new_cost, p.used));
            }

            if (!p.used) {
                ll new_cost = dist[p.idx][p.used] + ch.cost / 2;
                if (new_cost < dist[ch.idx][1]) {
                    dist[ch.idx][1] = new_cost;
                    pq.push(node(ch.idx, new_cost, 1));
                }
            }
        }
    }
    return dist[n][1];
}

void clear() {
    for (int i = 1; i <= n; i++)
        adj[i].clear();
}

void solve() {
    cin >> n >> m;
    int u, v, cost;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> cost;
        adj[u].emplace_back(v, cost, 0);
    }

    cout<<Dij();
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
