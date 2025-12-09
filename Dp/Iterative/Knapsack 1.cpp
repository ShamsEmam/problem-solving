#include <bits/stdc++.h>

using namespace std;

#define all(s) s.begin(), s.end()
#define sz(s) (int)(s).size()
#define ll long long

const ll oo = 1e15;
int const N = 4e2 + 5;


void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
    }
    ll dp[n + 1][k + 1];
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int sum = 0; sum <= k; ++sum) {
            dp[i][sum] = dp[i - 1][sum];

            if (sum - v[i - 1].first >= 0) {
                int newC = sum - v[i - 1].first;
                dp[i][sum] = max(dp[i][sum], dp[i - 1][newC] + v[i - 1].second);
            }
        }
    }
    cout << dp[n][k];
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
