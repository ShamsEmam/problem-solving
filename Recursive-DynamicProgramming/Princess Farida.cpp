#include <bits/stdc++.h>

using namespace std;

#define int long long

int n;
const int N = 1e4 + 5;
int dp[N], a[N];

int REC(int idx) {
    if (idx >= n)
        return 0;
    if (~dp[idx])
        return dp[idx];

    int op1 = a[idx] + REC(idx + 2);
    int op2 = REC(idx + 1);
    return dp[idx] = max(op1, op2);
}

int cnt = 1;

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << "Case " << cnt << ": " << REC(0) << "\n";
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
    cin >> t;
    while (t--) {
        solve();
        cnt++;
    }
    return 0;
}
