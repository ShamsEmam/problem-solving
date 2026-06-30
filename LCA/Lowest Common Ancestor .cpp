#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(s) s.begin(), s.end()
#define sz(s) (int)(Qry).size()
const int LG = 18, B = 337, N = 5e5 + 5;
vector<vector<int>> adj;
vector<vector<int>> anc;
int lvl[N];

void init(int n) {
    adj.assign(n + 1, {});
    anc.assign(LG, vector<int>(n + 1));
}

void dfs(int node, int par) {
    for (auto &ch: adj[node]) {
        if (ch == par)continue;
        anc[0][ch] = node;
        lvl[ch] = lvl[node] + 1;
        dfs(ch, node);
    }
}

int LCA(int u, int v) {
    if (lvl[v] > lvl[u])
        swap(v, u);

    int diff = abs(lvl[v] - lvl[u]);
    for (int i = 0; diff; i++, diff >>= 1) {
        if (diff & 1) {
            u = anc[i][u];
        }
    }
    if (u == v)return u;

    for (int i = LG - 1; i >= 0; i--) {
        int au = anc[i][u], av = anc[i][v];
        if (au != av) {
            u = au, v = av;
        }
    }
    return anc[0][u];
}

void solve() {
    int n;
    cin >> n;
    init(n);
    int u;
    for (int v = 1, sz; v <= n; ++v) {
        cin >> sz;
        while (sz--) {
            cin >> u;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    dfs(1, 0);
    for (int msk = 1; msk < LG; ++msk) {
        for (u = 1; u <= n; ++u) {
            anc[msk][u] = anc[msk - 1][anc[msk - 1][u]];
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int v;
        cin >> u >> v;
        cout << LCA(u, v) << '\n';
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

#undef int

int main() {
    setupIO();
    speed();
    int t = 1, tt = 1;
    cin >> t;
    while (t--) {
        cout << "Case " << tt++ << ":\n";
        solve();
    }
    return 0;
}
