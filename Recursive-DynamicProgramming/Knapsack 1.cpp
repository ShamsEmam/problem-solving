#include <bits/stdc++.h>
using namespace std;

#define int long long

int const N = 1e2,M=1e5+5;
int dp[N][M];

int rec(vector<pair<int, int>> &p, int idx, int cnt) {
    if (cnt==0 || idx>=p.size())
        return 0;

    if (dp[idx][cnt]!=-1)
        return dp[idx][cnt];

    int take = 0;


    if (cnt >= p[idx].second)
        take =  p[idx].first+rec(p, idx + 1, cnt - p[idx].second);
    
    int leave = rec(p, idx + 1, cnt);


    return dp[idx][cnt] = max(take, leave);
}

void solve() {
    int n, cap;
    cin >> n >> cap;

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].second >> v[i].first;


    memset(dp, -1, sizeof(dp));

    cout << rec(v, 0, cap) << '\n';
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
