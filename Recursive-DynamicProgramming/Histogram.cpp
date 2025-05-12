#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ld long double
int const N = 16;
int n, arr[20];
pair<int, int> dp[1 << N][N];

pair<int, int> s0lve(int msk, int prv) {
    if (msk == (1 << n)-1)
        return {arr[prv], 1};

    auto &ret = dp[msk][prv];
    if (~dp[msk][prv].first)
        return ret;

    ret = {-1e9, 0};

    for (int i = 1; i <= n; ++i) {
        if( (msk >> (i-1)) & 1)continue;

        pair<int, int> go = s0lve(msk | (1 <<( i-1)), i);
        go.first += abs(arr[prv] - arr[i])+2;

        if (go.first > ret.first) {
            ret = go;
        } else if (go.first == ret.first) {
            ret.second += go.second;
        }
    }
    return ret;
}

void solve() {
    while (true) {
        cin >> n;
        if (n == 0)
            exit(0);
        arr[0] = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
        }
        for (int i = 0; i < (1 << (n + 1)); i++)
            for (int j = 0; j <= n; ++j)
                dp[i][j] = {-1, -1};


        pair<int, int> ans = s0lve(0, 0);

        cout << ans.first << " " << ans.second << '\n';
    }
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
    setupIO();
    speed();
    int t = 1;
//    cin >> t;
    while (t--) solve();
    return 0;
}
