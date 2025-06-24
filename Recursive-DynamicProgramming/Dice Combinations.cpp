#include <bits/stdc++.h>

using namespace std;

#define int long long
int const N = 2e6 + 10, mod = 1e9 + 7;
int n;
int dice[] = {1, 2, 3, 4, 5, 6};
int dp[N];

int add(int a, int b, int m) {
    return ((a % m) + (b % m)) % m;
}

int rec(int sum) {
    if (sum == 0)
        return 1;
    if (sum <= 0)
        return 0;
    int &val = dp[sum];
    if (~val)
        return val;
    val = 0;
    for (int i = 1; i <= 6; ++i) {
        if (sum - i >= 0)
            val = add(val, rec(sum - i), mod);
    }
    return val;
}

void solve() {
    cin >> n;
    memset(dp, -1, sizeof dp);
    cout << rec(n) << ' ';
}

void speed() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}


void setupIO() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}
signed main() {
    speed();
    setupIO();
    int t = 1;
//    cin>>t;
    while (t--) solve();
    return 0;
}
