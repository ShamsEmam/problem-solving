#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ld long double
int const N = 1e5 + 10;
int sm[N][20];
int a[N], lg[N];

void buildSparseTable(int n) {
    for (int i = 2; i <= n; ++i)
        lg[i] = lg[i / 2] + 1;

    for (int i = 0; i < n; ++i)
        sm[i][0] = a[i];

    for (int j = 1; j < 20; ++j) {  
        for (int i = 0; i + (1 << j) <= n; ++i) {
            sm[i][j] = min(sm[i][j - 1], sm[i + (1 << (j - 1))][j - 1]);
        }
    }
}

// O(log n) sum query using sparse table
int query(int l, int r) {
    int dens = r - l + 1;
    int ans = 0;
    for (int i = 19; i >= 0; --i)
        if (dens >> i & 1)
            ans += sm[l][i], l += (1 << i);
    return ans;
}

// O(1) min query
int query2(int L, int R) {
    int j = lg[R - L + 1];
    return min(sm[L][j], sm[R - (1 << j) + 1][j]);
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }

    buildSparseTable(n);

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << query2(l, r) << '\n';
    }
}


signed main() {
    int t = 1;
    while (t--) solve();
    return 0;
}
