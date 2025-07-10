#include <bits/stdc++.h>

#define int long long
using namespace std;
const int MOD = 1e9 + 7;
const int N = 100007;

vector<int> adj[N];
int vis[N];
bool valid = true;

void dfs(int node, int Type) {
    vis[node] = Type;
    for (auto &i: adj[node]) {
        if (vis[i]) {
            if (vis[i] == Type)
                valid = false;
            continue;
        }
        dfs(i, 3 - Type);
    }
}

int cnt = 1;

void solve() {
    cout << "Scenario #" << cnt << ':' << '\n';

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        vis[i] = 0;
        adj[i].clear();
    }
    int u, v;
    for (int i = 1; i <= m; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    valid = true;
    for (int i = 1; i <= n; ++i)
        if (!vis[i])
            dfs(i, 1);

    if (!valid)
        cout << "Suspicious bugs found!\n";
    else
        cout << "No suspicious bugs found!\n";
}

void speed() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
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
    cin >> t;
    while (t--) solve(), cnt++;
    return 0;
}
