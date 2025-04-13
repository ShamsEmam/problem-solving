#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 4005;
int dp[N], a, b, c;

int REC(int n) {
    if (n == 0) return 0;
    if (n < 0) return LLONG_MIN;

    int &ret = dp[n];
    if (~ret) return ret;

    int op1 = 1 + REC(n - a);
    int op2 = 1 + REC(n - b);
    int op3 = 1 + REC(n - c);

    return ret = max({op1, op2, op3});
}

void solve() {
    int target;
    cin >> target >> a >> b >> c;

    memset(dp, -1, sizeof dp);
    cout << REC(target) << '\n';
}


void speed() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
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
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
