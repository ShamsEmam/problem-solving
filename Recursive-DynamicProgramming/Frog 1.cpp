#include <bits/stdc++.h>

using namespace std;

#define int long long
const int N = 200005;
int v[N], dp[N];
int n;

int REC(int idx) {
    if (idx == n - 1) return 0;
    if (dp[idx] != -1) return dp[idx];

    int op1 = LLONG_MAX, op2 = LLONG_MAX;

    if (idx + 1 < n) op1 = abs(v[idx] - v[idx + 1]) + REC(idx + 1);
    if (idx + 2 < n) op2 = abs(v[idx] - v[idx + 2]) + REC(idx + 2);

    return dp[idx] = min(op1, op2);
}

void solve() {
    cin >> n;

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
