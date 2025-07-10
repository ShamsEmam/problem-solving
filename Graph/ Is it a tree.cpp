#include <bits/stdc++.h>

#define int long long
using namespace std;
const int MOD = 1e9 + 7;
const int N = 2e5 + 7;

vector<int> adj[N];
bool vis[N];

void dfs(int node) {
    vis[node] = true;
    for (auto &i: adj[node]) {
        if (vis[i])
            continue;
        dfs(i);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    int u, v;
    for (int i = 1; i <= m; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
    }
    int ans = 1;
    dfs(1);
    for (int i = 1; i <= n; i++) {
        if (vis[i])
            continue;
        ans++;
        dfs(i);
    }
    if (ans == 1 and m == n - 1)
        cout << "YES\n";
    else
        cout << "NO\n";
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

signed main() {
    setupIO();
    speed();
    int t = 1;
//    cin >> t;
    while (t--) solve();
    return 0;
}
