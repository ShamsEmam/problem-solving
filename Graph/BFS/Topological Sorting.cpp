#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(s) s.begin(), s.end()
#define sz(s) (int)(s).size()
int const N = 1e6 + 5;

vector<int> adj[N];
//bool vis[N];
int n, m;
vector<int> lvl, InDegree, Topological;

void bfs() {
    priority_queue<int, vector<int>, greater<int>> q;
    for (int start = 1; start <= n; start++) {
        if (!InDegree[start]) {
            q.push(start);
            lvl[start] = 0;
        }
    }


    while (!q.empty()) {
        int node = q.top();
        q.pop();

        Topological.push_back(node);

        for (auto child: adj[node]) {
            InDegree[child]--;
            if (!InDegree[child]) {
                lvl[child] = lvl[node] + 1;
                q.push(child);

            }
        }
    }
}


void solve() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        adj[i].clear();
    }

    lvl.assign(n + 1, 0);
    InDegree.assign(n + 1, 0);
    Topological.clear();

    int u, v;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        InDegree[v]++;
    }

    bfs();
    if (sz(Topological) != n)cout << "Sandro fails.";
    else
        for (auto &i: Topological)cout << i << ' ';

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
