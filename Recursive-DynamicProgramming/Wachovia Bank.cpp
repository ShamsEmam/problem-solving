#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1005;
int dp[N][N];
int n, k;
vector<int> w, val;

int REC(int idx, int sum) {
    // base case
    if (idx == k)
        return 0;

    if (dp[idx][sum] != -1)
        return dp[idx][sum];

    int op1 = 0, op2 = 0;

    if (sum + w[idx] <= n)
        op1 = REC(idx + 1, sum + w[idx]) + val[idx];


    op2 = REC(idx + 1, sum);

    return dp[idx][sum] = max(op1, op2);
}

void solve() {
    cin >> n >> k;

    w.resize(k);
    val.resize(k);

    for (int i = 0; i < k; i++)
        cin >> w[i] >> val[i];

    fill(&dp[0][0], &dp[0][0] + N * N, -1);

    cout<<"Hey stupid robber, you can get ";
    cout << REC(0, 0) << ".\n";
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
    cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}
