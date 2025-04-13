#include <bits/stdc++.h>

using namespace std;

#define int long long
const int N = 200005;
int v[N], dp[N];
int n, k;

int REC(int idx) {
    if (idx == n - 1) return 0;
    if (dp[idx] != -1) return dp[idx];

    int op1 = LLONG_MAX, op2 = LLONG_MAX;
    for (int i = 1; i <= k; ++i) {
        if (idx + i < n) op1 = min(op1,abs(v[idx] - v[idx + i]) + REC(idx + i));
    }

    return dp[idx] = op1;
}

void solve() {
    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    memset(dp, -1, sizeof(dp));
    cout << REC(0) << '\n';
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
