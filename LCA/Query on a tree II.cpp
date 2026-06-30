#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(s) s.begin(), s.end()
#define sz(s) (int)(Qry).size()

const int LG = 20, B = 337, N = 5e5 + 5;

vector<vector<pair<int, int>>> adj;
vector<vector<int>> anc;
int lvl[N];
ll pref[N];

void init(int n) {
    adj.assign(n + 1, {});
    anc.assign(LG, vector<int>(n + 1, 0));
    fill(lvl, lvl + n + 1, 0);
    fill(pref, pref + n + 1, 0);
}

void dfs(int node, int par) {
    anc[0][node] = par;
    for (auto &ch: adj[node]) {
        if (ch.first == par) continue;

        lvl[ch.first] = lvl[node] + 1;
        pref[ch.first] = pref[node] + ch.second;
        dfs(ch.first, node);
    }
}

int LCA(int u, int v) {
    if (lvl[v] > lvl[u])
        swap(v, u);

    int diff = lvl[u] - lvl[v];
    for (int i = 0; i < LG; i++) {
        if (diff & (1 << i)) {
            u = anc[i][u];
        }
    }

    if (u == v) return u;

    for (int i = LG - 1; i >= 0; i--) {
        if (anc[i][u] != anc[i][v]) {
            u = anc[i][u];
            v = anc[i][v];
        }
    }

    return anc[0][u];
}


int KthAnc(int u, int k) {
    for (int i = 0; k; ++i, k >>= 1) {
        if (k & 1) {
            u = anc[i][u];
        }
    }
    return u;
}

int dist(int u, int v) {
    int lca = LCA(u, v);
    return abs(lvl[lca] - lvl[u]) + abs(lvl[lca] - lvl[v]);
}

int KthNode(int u, int v, int k) {
    int lca = LCA(u, v);
    int len1 = lvl[u] - lvl[lca] + 1;

    if (k <= len1)
        return KthAnc(u, k - 1);

    int len2 = lvl[v] - lvl[lca];

    return KthAnc(v, len2 - (k - len1));

}


ll PathSum(int u, int v) {
    int lca = LCA(u, v);
//    return pref[u] + pref[v] - 2 * pref[lca];
    return abs(pref[lca] - pref[u]) + abs(pref[lca] - pref[v]);
}

void solve() {
    int n;
    cin >> n;
    init(n);

    int u, w, v;

    for (int i = 1; i < n; ++i) {
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    dfs(1, 0);

    for (int i = 1; i < LG; ++i) {
        for (u = 1; u <= n; ++u) {
            anc[i][u] = anc[i - 1][anc[i - 1][u]];
        }
    }

    int k;
    string type;

    while (true) {
        cin >> type;
        if (type == "DONE")
            break;
        if (type[0] == 'D') {
            cin >> u >> v;
            cout << PathSum(u, v) << '\n';
        } else if (type[0] == 'K') {
            cin >> u >> v >> k;
            cout << KthNode(u, v, k) << '\n';
        }

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
        solve();
    }
    return 0;
}
