#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define all(s) s.begin(), s.end()
#define sz(s) (int)(s).size()
const int N = 2e5 + 5;
 
int n, m;
vector<int> adj[N];
bool vis[N];
 
void dfs(int node) {
    vis[node] = true;
    for (auto child: adj[node])
        if (!vis[child])
            dfs(child);
}
 
void solve() {
    cin >> n >> m;
    int x, y;
    while (m--) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> ans;
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            ans.push_back(i);
            dfs(i);
        }
    }
    cout << sz(ans)-1 << '\n';
    for (int i = 1; i < sz(ans); i++)
        cout << ans[i - 1] << ' ' << ans[i] << "\n";
//    cout << '\n';
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
    // cin >> t;
    while (t--) solve();
    return 0;
}
