#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ld long double
int const N = 2e5 + 10;
int mn[N][22];
int a[N], lg[N];

void buildSparseTable(int n) {
    for (int i = 2; i <= n; ++i)
        lg[i] = lg[i / 2] + 1;

    for (int i = 0; i < n; ++i)
        mn[i][0] = a[i];

    for (int j = 1; j < 20; ++j) {
        for (int i = 0; i + (1 << j) <= n; ++i) {
            mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
        }
    }
}

// O(1) min,max,gcd query
int query2(int L, int R) {
    int j = lg[R - L + 1];
    return min(mn[L][j], mn[R - (1 << j) + 1][j]);
}

void solve() {
    int n, k;
    cin >> n >> k;

    int mx = LLONG_MIN;
    int mnVal = LLONG_MAX;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mx = max(mx, a[i]);
        mnVal = min(mnVal, a[i]);
    }
    buildSparseTable(n);
    if (k == 1) {
        cout << mnVal;
    }
    else if (k >= 3)
        cout << mx;
    else {
        int ans = LLONG_MIN;
        for (int i = 0; i < n; ++i) {
            int mn1 = query2(0, i);
            int mn2 = query2(i + 1, n - 1);
            ans = max({ans, mn1, mn2});
        }
        cout << ans << '\n';
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
