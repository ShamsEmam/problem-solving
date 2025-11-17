#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define all(s) s.begin(), s.end()
#define sz(s) (int)(s).size()
int const N = 2e5 + 5;
 
vector<int> adj[N];
bool vis[N];
vector<int> lvl, parent;
int n, m;
 
void bfs(int start) {
    queue<int> q;
    q.push(start);
    vis[start] = true;
    parent[start] = -1;
 
    while (!q.empty()) {
        int node = q.front();
        q.pop();
 
        for (int child: adj[node]) {
            if (!vis[child]) {
                vis[child] = true;
                lvl[child] = lvl[node] + 1;
                parent[child] = node;
                q.push(child);
            }
        }
    }
}
 
vector<int> get_path(int end) {
    vector<int> path;
    int cur = end;
    while (cur != -1) {
        path.push_back(cur);
        cur = parent[cur];
    }
    reverse(all(path));
    return path;
}
 
void solve() {
    cin >> n >> m;
 
    lvl.assign(n + 1, 0);
    parent.assign(n + 1, 0);
 
    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    bfs(1);
 
    if (!vis[n]) {
        cout << "IMPOSSIBLE";
        return;
    }
 
    vector<int> path = get_path(n);
 
    cout << sz(path) << "\n";
    for (int x: path) cout << x << " ";
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
