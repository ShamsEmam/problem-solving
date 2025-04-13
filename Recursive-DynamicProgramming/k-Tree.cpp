#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007

int const N = 2e2 + 5;
int n, k, d, dp[N][2];

int add(int x,int y) {
    return (x + y) % mod;
}

int REC(int rem, bool flag) {
    if (!rem) return flag;

    int &val = dp[rem][flag];
    if (~val)
        return dp[rem][flag];

    val = 0;
    for (int i = 1; i <= min(k, rem); i++)
        val = add(val, REC(rem - i, i >= d ? true : flag));

    return val;
}

void solve() {
    cin >> n >> k >> d;
    memset(dp, -1, sizeof(dp));
    cout << REC(n, 0);
}

void speed() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void setupIO() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
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
