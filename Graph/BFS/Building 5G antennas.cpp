#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(s) s.begin(), s.end()
#define sz(s) (int)(s).size()
int const N = 1e5 + 5;

int n, k;
bool vis[N];
vector<int> adj[N], ans;
vector<int> dist;

priority_queue<int, vector<int>, greater<>> pq;

void bfs() {
    pq.push(1);
    dist[1] = 0;

    while (!pq.empty()) {
        int cur = pq.top();
        pq.pop();

        if (vis[cur]) continue;


        vis[cur] = true;
        ans.push_back(cur);


        queue<pair<int, int>> q;
        q.push({cur, 0});

        while (!q.empty()) {
            auto [node, d] = q.front();
            q.pop();


            if (d < k) {
                for (auto ch: adj[node]) {
                    if (!vis[ch] && d + 1 < dist[ch]) {
                        dist[ch] = d + 1;

                        if (dist[ch] <= k) {
                            pq.push(ch);
                        }
                        q.push({ch, d + 1});
                    }
                }
            }
        }
    }
}

void solve() {
    cin >> n >> k;
    int u, v;
    dist.assign(n + 1, 1e9);

    for (int i = 1; i < n; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs();
    for (auto &a: ans) cout << a << ' ';
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
    while (t--) solve();
    return 0;
}
