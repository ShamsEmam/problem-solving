#include <bits/stdc++.h>

using namespace std;

#define int long long
const int N = 2e5 + 10;

int mn[N][25], mx[N][25], arr[N], lg[N];
int s[N];

void BuildSpare(int Size) {

    for (int i = 2; i <= Size; i++)
        lg[i] = lg[i / 2] + 1;

    for (int i = 0; i < Size; i++)
        mn[i][0] = mx[i][0] = s[i];

    for (int i = 1; i < 20; ++i) {
        for (int j = 0; j + (1 << i) + 1 <= Size; ++j) {
            mn[j][i] = min(mn[j][i - 1], mn[j + (1 << (i - 1))][i - 1]);
            mx[j][i] = max(mn[j][i - 1], mn[j + (1 << (i - 1))][i - 1]);
        }
    }
}

pair<int, int> query(int l, int r) {
    if (l > r)
        return {LLONG_MAX, LLONG_MIN};
    int dis = r - l + 1;
    int j = lg[dis];

    return {
            min(mn[l][j], mn[r - (1 << j) + 1][j]),
            max(mx[l][j], mx[r - (1 << j) + 1][j])
    };
}

void solve() {
    int n, m;
    cin >> n >> m;
    string S;
    cin >> S;

    for (int i = 0; i < n; ++i)
        arr[i] = (S[i] == '+') ? 1 : -1;

    s[0] = 0;
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + arr[i - 1];

    BuildSpare(n + 1);
    while (m--) {
        int l, r;
        cin >> l >> r;

        auto pre = query(0, l - 1);
        auto suf = query(r, n);

        int shift = s[r] - s[l - 1];

        int MnVal = min(pre.first, suf.first - shift);
        int MxVal = max(pre.second, suf.second - shift);

        cout << MxVal - MnVal + 1 << '\n';
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
    cin >> t;
    while (t--) solve();
    return 0;
}
