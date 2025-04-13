#include <bits/stdc++.h>

using namespace std;

#define int long long
const int N = 1005, mod = 1e9 + 7;

int n, m;
char s[N][N];
int dp[N][N];
int dx[] = {1, 0};
int dy[] = {0, 1};

bool valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && s[x][y] == '.';
}

int add(int x, int y) {
    return (x + y) % mod;
}

int countPaths(int i, int j) {
    if (!valid(i, j)) return 0;
    if (i == n - 1 && j == m - 1) return 1;
    if (dp[i][j] != -1) return dp[i][j];

    int ways = 0;
    for (int k = 0; k < 2; ++k) {
        int ni = i + dx[k];
        int nj = j + dy[k];
        ways = add(ways, countPaths(ni, nj));
    }

    return dp[i][j] = ways;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> s[i][j];

    memset(dp, -1, sizeof dp);

    cout << countPaths(0, 0) << "\n";
}

void speed() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
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
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
