#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 100;
int dp[N][N + 1];
int n;
vector<int> arr;

int REC(int idx, int last_idx) {
    // base case
    if (idx == n)
        return 0;

    if (dp[idx][last_idx + 1] != -1)
        return dp[idx][last_idx + 1];

    int op1 = 0, op2 = 0;


    if (last_idx == -1 || arr[idx] > arr[last_idx])
        op1 = 1 + REC(idx + 1, idx);


    op2 = REC(idx + 1, last_idx);

    return dp[idx][last_idx + 1] = max(op1, op2);
}

void solve() {
    cin >> n;

    arr.resize(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    memset(dp, -1, sizeof(dp));

    cout << REC(0, -1) << '\n';
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
    // cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}
