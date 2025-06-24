#include <bits/stdc++.h>

using namespace std;

#define int long long
int const N = 2e5 + 10;
int Xor[N][20], a[N], lg[N];
void buildSparseTable(int n) {
    for (int i = 2; i <= n; ++i)
        lg[i] = lg[i / 2] + 1;

    for (int i = 0; i < n; ++i)
        Xor[i][0] = a[i];

    for (int j = 1; (1 << j) <= n; ++j) {
        for (int i = 0; i + (1 << j) <= n; ++i) {
            Xor[i][j] = Xor[i][j - 1] ^ Xor[i + (1 << (j - 1))][j - 1];
        }
    }
}

//O(log) min ,max,__gcd ,sum  ,XoR
int query(int l, int r) {

    int dens = r - l + 1;
    int ans = 0;

    for (int i = 19; i >= 0; --i)
        if (dens >> i & 1)
            ans ^= Xor[l][i], l += (1 << i);

    return ans;
}


void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)cin >> a[i];

    buildSparseTable(n);
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << query(l, r) << '\n';
    }
}

void speed() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}


signed main() {
    speed();
    int t = 1;
    while (t--) solve();
    return 0;
}
