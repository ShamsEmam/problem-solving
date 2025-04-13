#include <bits/stdc++.h>

using namespace std;

#define int long long
const int N = 100005, mod = 1e9 + 7;
int n, k, dp[N];

int add(int a, int b) {
    return ((a + b) % mod + mod) % mod;
}

int REC(int idx) {
    if (idx == 0)
        return 1;
    if (idx < 0)
        return 0;

    int &val = dp[idx];
    if (~val)
        return val;

    val = REC(idx - 1);

    val = add(val, REC(idx - k));
    return val;

}

void solve() {
    cin >> n >> k;

    memset(dp, -1, sizeof(dp));
    REC(1e5);

    for (int i = 1; i <= 1e5; i++) {
        dp[i] = add(dp[i - 1], dp[i]);
    }
    while (n--) {
        int a, b;
        cin >> a >> b;
        cout << add(dp[b], -dp[a - 1]) << '\n';
    }
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
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
