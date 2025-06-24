#include <bits/stdc++.h>

using namespace std;

#define int long long
int const N = 1e6 + 10, mod = 1e9 + 7;
int arr[105], dp[N];


void solve() {
    int n, target;
    cin >> n >> target;

    for (int i = 0; i < n; i++)cin >> arr[i];

    for (int i = 0; i <= target; i++)dp[i] = 1e9;
    dp[0]=0;

    for (int sum = 1; sum <= target; sum++) {
        for (int j = 0; j < n; ++j) {
            if (sum - arr[j] >= 0)
                dp[sum] = min(dp[sum], 1 + dp[sum - arr[j]]);
        }
    }
    if (dp[target] == 1e9)
        cout << -1;
    else
        cout << dp[target];
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
