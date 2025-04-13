#include <bits/stdc++.h>

using namespace std;

#define int long long

int n;
const int N = 8e4 + 5;
int dp[6][N];
int arr[5] = {50, 25, 10, 5, 1};

int REC(int idx, int rem) {
    if (rem == 0) return 1;
    if (idx == 5 || rem < 0) return 0;

    if (dp[idx][rem] != -1)
        return dp[idx][rem];

    int take = REC(idx, rem - arr[idx]);
    int leave = REC(idx + 1, rem);

    return dp[idx][rem] = leave + take;
}

void solve() {
    while (cin >> n) {
        cout <<  REC(0, n) <<"\n";
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
        memset(dp, -1, sizeof(dp));
        solve();
    }
    return 0;
}
