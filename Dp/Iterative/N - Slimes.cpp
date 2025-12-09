#include <bits/stdc++.h>

using namespace std;

#define all(s) s.begin(), s.end()
#define sz(s) (int)(s).size()
#define ll long long

const ll oo = 1e18;
int const N = 4e2 + 5;


void solve() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for (auto &i: v)cin >> i;

    ll dp[n][n];

    vector<ll> prf(n + 1);
    for (int i = 1; i <= n; i++)
        prf[i] = prf[i - 1] + v[i - 1];

    dp[0][0] = 0;
    for (int len = 1; len <= n; len++) {
        for (int l = 0; l + len - 1 < n; ++l) {
            int r = len + l - 1;
            if (l == r) {
                dp[l][r] = 0;
                continue;
            }
            dp[l][r] = oo;
            for (int k = l; k < r; ++k) {
                dp[l][r] = min({dp[l][r], dp[l][k] + dp[k + 1][r] + prf[r + 1] - prf[l]});
            }
        }
    }
    cout << dp[0][n - 1];
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--)solve();
    return 0;
}
