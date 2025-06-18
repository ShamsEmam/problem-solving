#include <bits/stdc++.h>

using namespace std;

#define int long long
const int N = 1e5 + 10;
int mx[N][25], arr[N], lg[N];

void buildSparse(int Size) {

    for (int i = 2; i <= Size; i++) {
        lg[i] = lg[i / 2] + 1;
    }
    for (int i = 0; i < Size; ++i) {
        mx[i][0] = arr[i];
    }

    for (int i = 1; i < 20; ++i) {
        for (int j = 0; j + (1 << (i - 1)) <= Size; ++j)
            //i =idx, j=pow of 2 ,calc sum[i][j]
            mx[j][i] = max(mx[j][i - 1], mx[j + (1 << (i - 1))][i - 1]);
    }
}


int query2(int l, int r) {
    int j = lg[r - l + 1];
    return max(mx[l][j], mx[r - (1 << j) + 1][j]);
}

void solve() {
    int n, q, d;
    cin >> n >> q;
    for (int i = 0; i < n; i++)cin >> arr[i];

    buildSparse(n);
    while (q--) {
        cin >> d;
        int mn = LLONG_MAX;
        for (int i = 0; i + d - 1 < n; i++)
            mn = min(query2(i, i + d - 1), mn);
        cout << mn << '\n';
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
