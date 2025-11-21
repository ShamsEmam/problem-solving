#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(s) s.begin(), s.end()
#define sz(s) (int)(s).size()
ll const N = 1e5 + 5,inf=1e15;

int n, m;

struct node {
    ll idx, cost;

    node(ll _idx, ll _cost) : idx(_idx), cost(_cost) {}

    node() {}
};

vector<node> adj[N];
ll dist[N],parent[N];

struct cmp {
    bool operator()(node &a, node &b) {
        return a.cost > b.cost;
    }
};

ll Dijkstra(int s, int d) {
    for (int i = 1; i <= n; ++i)
        dist[i] = inf;

    priority_queue<node, vector<node>, cmp> pq;

    dist[s] = 0;
    pq.push({s, 0});
    parent[s] = s;

    while (!pq.empty()) {
        node p = pq.top();
        pq.pop();

        if (p.cost>dist[p.idx])continue;

        for (auto ch: adj[p.idx]) {
            ll newCost = p.cost + ch.cost;

            if (newCost < dist[ch.idx]) {
                dist[ch.idx] = newCost;
                parent[ch.idx] = p.idx;
                pq.push(node(ch.idx, newCost));
            }
        }
    }
    return dist[d];
}

void path(int dest) {
    if (dist[dest] == inf) {
        cout << "-1\n";
        return;
    }
    vector<int> ans;
    int cur = dest;

    while (true) {
        ans.push_back(cur);
        if (cur == parent[cur]) break;
        cur = parent[cur];
    }

    reverse(ans.begin(), ans.end());
    for (auto x: ans)
        cout << x << ' ';
}


void solve() {
    cin >> n >> m;

    int u, v, cost;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> cost;
        adj[u].push_back({v, cost});
        adj[v].push_back({u, cost});
    }

    Dijkstra(1, n);
    path(n);
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
