 
#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1e5 + 5;
int dp[N];
map<int, int> freq;
vector<int> unique_vals;

int REC(int idx) {
    if (idx >= unique_vals.size())
        return 0;

    if (dp[idx] != -1)
        return dp[idx];

    int val = unique_vals[idx];
    int take = val * freq[val];

    int next_idx = idx + 1;
    if (next_idx < unique_vals.size() && unique_vals[next_idx] == val + 1) {
        next_idx++;
    }

    take += REC(next_idx);
    int skip = REC(idx + 1);

    return dp[idx] = max(take, skip);
}

void solve() {
    int n;
    cin >> n;

    freq.clear();
    unique_vals.clear();
    memset(dp, -1, sizeof(dp));

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        freq[a[i]]++;
    }

    for (auto it : freq) {
        unique_vals.push_back(it.first);
    }

    cout << REC(0) << "\n";
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
