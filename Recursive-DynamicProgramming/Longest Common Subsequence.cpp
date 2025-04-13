#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<vector<int>> dp;
string str1, str2;

int REC(int i, int j) {
    if (i == str1.size() || j == str2.size())
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (str1[i] == str2[j])
        return dp[i][j] = 1 + REC(i + 1, j + 1);

    return dp[i][j] = max(REC(i + 1, j), REC(i, j + 1));
}

void solve() {
    while (getline(cin, str1) && getline(cin, str2)) {
        int n = str1.size(), m = str2.size();
        dp.assign(n + 1, vector<int>(m + 1, -1));
        cout << REC(0, 0) << '\n';
    }
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
    while (t--) {
        solve();
    }
    return 0;
}
