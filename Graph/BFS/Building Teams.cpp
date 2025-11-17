#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(s) s.begin(), s.end()
#define sz(s) (int)(s).size()
int const N = 2e5 + 5;

vector<int> adj[N],no_nodes[N];
bool vis[N];
int n, m;
vector<int> lvl, teams;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    vis[start] = true;
    lvl[start] = 0;
    teams[start] = 1;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto child: adj[node]) {
            if (!vis[child]) {
                vis[child] = true;
                lvl[child] = lvl[node] + 1;
                teams[child] = 3 - teams[node];
                q.push(child);
            }
            else {
                if (teams[child] == teams[node]) {
                    cout << "IMPOSSIBLE\n";
                    exit(0);
                }
            }
        }
    }
}


void solve() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        vis[i] = false;
    }

    lvl.assign(n + 1, 0);
    teams.assign(n + 1, 0);
    int u, v;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) bfs(i);
    }

    for (int i = 1; i <= n; i++)
        cout << teams[i] << " ";
}


void speed() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}



signed main() {
    speed();
    int t = 1;
    while (t--) solve();
    return 0;
}
