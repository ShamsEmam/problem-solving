#include <bits/stdc++.h>

using namespace std;

#define all(s) s.begin(), s.end()
#define sz(s) (int)(s).size()
#define ll long long

const ll oo = 1e9;
int const N = 4e2 + 5;


void solve() {
    int n;
    cin >> n;
    vector<array<int, 3>> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i][0] >> v[i][1] >> v[i][2];

    int dp[n][3];
    for (int i = 0; i < n; ++i)
        dp[i][0] = dp[i][1] = dp[i][2] = -oo;

    dp[0][0] = v[0][0];
    dp[0][1] = v[0][1];
    dp[0][2] = v[0][2];
    for (int i = 1; i < n; ++i) {
        dp[i][0] = max(dp[i][0], dp[i - 1][1] + v[i][0]);
        dp[i][0] = max(dp[i][0], dp[i - 1][2] + v[i][0]);
        dp[i][1] = max(dp[i][1], dp[i - 1][0] + v[i][1]);
        dp[i][1] = max(dp[i][1], dp[i - 1][2] + v[i][1]);
        dp[i][2] = max(dp[i][2], dp[i - 1][1] + v[i][2]);
        dp[i][2] = max(dp[i][2], dp[i - 1][0] + v[i][2]);
    }
    cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
}

void setupIO() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    setupIO();
    int t = 1;
//    cin >> t;
    while (t--)solve();
    return 0;
}
