#include <bits/stdc++.h>

using namespace std;

#define all(s) s.begin(), s.end()
#define sz(s) (int)(s).size()
#define ll long long

const int oo = 1e9;
int const N = 4e2 + 5;


void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i: v)cin >> i;

    int dp[n];
    for (int i = 0; i < n; ++i)
        dp[i] = oo;

    dp[0] = 0;
    dp[1] = abs(v[1] - v[0]);
    for (int i = 2; i < n; ++i) {
        int op1 = dp[i - 1] + abs(v[i] - v[i - 1]);
        int op2 = dp[i - 2] + abs(v[i] - v[i - 2]);
        dp[i] = min(op1, op2);
    }
    cout << dp[n - 1];
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
