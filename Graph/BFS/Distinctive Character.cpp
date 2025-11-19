#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(s) s.begin(), s.end()
#define sz(s) (int)(s).size()
int const N = 2e3 + 5;

int n, k;
vector<bool> vis;
vector<int> masks, dis;

void bfs() {
    queue<int> q;

    for (int mask = 0; mask < sz(masks); ++mask) {
        q.push(masks[mask]);
        dis[masks[mask]] = 0;
        vis[masks[mask]] = true;
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        int neighbor;
        for (int bit = 0; bit < k; ++bit) {
            neighbor = cur ^ (1 << bit);
            if (!vis[neighbor]) {
                dis[neighbor] = dis[cur] + 1;
                vis[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

void solve() {
    cin >> n >> k;
    vis.assign(1 << k, 0);
    dis.assign(1 << k, -1);
    string s = "";
    for (int i = 0; i < n; ++i) {
        cin >> s;
        int x = 0;
        for (int j = 0; j < sz(s); j++) {
            if (s[j] == '1') {
                x |= (1 << j);
            }
        }
        masks.push_back(x);
    }
    masks.erase(unique(all(masks)), masks.end());
    bfs();
    int ans = -1;
    int sol = -1;
    for (int i = 0; i < (1 << k); ++i) {
        if (dis[i] > ans) {
            ans = dis[i];
            sol = i;
        }
    }
    for (int i = 0; i < k; ++i) {
        cout << ((sol >> i) & 1);
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

int main() {
    setupIO();
    speed();
    int t = 1;
//    cin >> t;
    while (t--) solve();
    return 0;
}
