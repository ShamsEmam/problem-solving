#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(s) s.begin(), s.end()
#define sz(s) (int)(s).size()
int const N = 1e6 + 5;

vector<int> adj[26];
//bool vis[N];
int n;
vector<int> lvl, InDegree, Topological;

void bfs() {
    priority_queue<int, vector<int>, greater<int>> q;

    for (int i = 0; i < 26; i++) {
        if (InDegree[i] == 0)
            q.push(i);
    }

    while (!q.empty()) {
        int node = q.top();
        q.pop();
        Topological.push_back(node);

        for (auto child: adj[node]) {
            InDegree[child]--;
            if (InDegree[child] == 0)
                q.push(child);
        }
    }
}


void solve() {
    cin >> n;

    for (int i = 1; i < 26; i++) {
        adj[i].clear();
    }

    lvl.assign(26, 0);
    InDegree.assign(26, 0);
    Topological.clear();
    vector<string> s(n);
    for (auto &a: s) cin >> a;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < sz(s[i]) - 1; ++j) {
            if (s[i][j] != s[i][j + 1]) {
                int u = s[i][j] - 'a';
                int v = s[i][j + 1] - 'a';

                adj[u].push_back(v);
                InDegree[v]++;
            }
        }
    }

    bfs();
    if (Topological.size() != 26)
        cout << "NAO";
    else {
        cout << "SIM\n";
        for (auto &i: Topological)cout << char(i + 'a');

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

signed main() {
    setupIO();
    speed();
    int t = 1;
//    cin >> t;
    while (t--) solve();
    return 0;
}
