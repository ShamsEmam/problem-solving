#include <bits/stdc++.h>
using namespace std;

#define int long long
int const N = 3010;
int dp[N][N];
string st1, st2, tmp;

int REC(int i,int j) {
    //base case
    if (i == st1.size() || j == st2.size())
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (st1[i] == st2[j]) {
        dp[i][j] = 1 + REC(i + 1, j + 1);
    } else {
        dp[i][j] = max(dp[i][j], REC(i, j + 1));
        dp[i][j] = max(dp[i][j], REC(i + 1, j));
    }

    return dp[i][j];
}

void bulid(int i,int j) {
    if (i == st1.size() || j == st2.size())
        return;

    if (st1[i] == st2[j]) {
        cout << st1[i];
        bulid(i + 1, j + 1);
    } else {
        if (REC(i, j + 1) > REC(i + 1, j)) {
            bulid(i, j + 1);
        } else {
            bulid(i + 1, j);
        }
    }
}

void solve() {
    cin >> st1 >> st2;
    memset(dp, -1, sizeof(dp));
    REC(0, 0);
    bulid(0, 0);
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
