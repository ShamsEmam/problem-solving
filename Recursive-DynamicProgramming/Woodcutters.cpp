#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1e5 + 5;

int n, a[N], h[N], dp[N][2];

int REC(int idx, bool flag) {
    if (idx == n) return 0;
    if (idx == n - 1)return 1;

    int &ret = dp[idx][flag];
    if (~ret) return ret;

    ret = REC(idx + 1, false);

    if (a[idx] + h[idx] < a[idx + 1])
        ret = max(ret, 1 + REC(idx + 1, true));

    if ((flag && a[idx] - (a[idx - 1] + h[idx - 1]) > h[idx]) || (!flag && a[idx] - a[idx - 1] > h[idx]))
        ret = max(ret, 1 + REC(idx + 1, false));

    return ret;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> h[i];
    }
    memset(dp, -1, sizeof dp);
    cout << 1 + REC(1,0) << '\n';
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
