#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ld long double
int const N = 50000 + 10;
int mx[N][25];
int a[N], lg[N];

void buildSparseTable(int n) {
    for (int i = 2; i <= n; ++i)
        lg[i] = lg[i / 2] + 1;

    for (int i = 0; i < n; ++i)
        mx[i][0] = a[i];

    for (int j = 1; j < 20; ++j) {
        for (int i = 0; i + (1 << j) <= n; ++i) {
            mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
        }
    }
}

// O(1) min,max,gcd query
int query2(int L, int R) {
    int j = lg[R - L + 1];
    return max(mx[L][j], mx[R - (1 << j) + 1][j]);
}
void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    buildSparseTable(n);
    int cnt = 0;

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        if (l > r) swap(l, r);
        if (l==r)
        {
            cnt++;
            continue;
        }
            int maxInBetween = query2(l , r-1);
            if (maxInBetween <= a[l]) cnt++;

    }
    cout << cnt;
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
