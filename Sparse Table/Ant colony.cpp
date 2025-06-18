#include <bits/stdc++.h>

using namespace std;

#define int long long
const int N = 1e5 + 10;
int GcD[N][25], arr[N], lg[N];

void buildSparse(int Size) {

    for (int i = 2; i <= Size; i++) {
        lg[i] = lg[i / 2] + 1;
    }
    for (int i = 0; i < Size; ++i) {
        GcD[i][0] = arr[i];
    }

    for (int i = 1; i < 20; ++i) {
        for (int j = 0; j + (1 << (i - 1)) <= Size; ++j)
            //i =idx, j=pow of 2 ,calc sum[i][j]
            GcD[j][i] = gcd(GcD[j][i - 1], GcD[j + (1 << (i - 1))][i - 1]);
    }
}

//long long query(int l, int r) {
//    int dist = r - l + 1;
//    int ans = 0;
//    for (int i = 0; i < 20; ++i) {
//        if ((dist >> i) & 1)
//            ans += mx[l][i], l += (1 << i);
//    }
//    return ans;
//}

int query2(int l, int r) {
    int j = lg[r - l + 1];
    return gcd(GcD[l][j], GcD[r - (1 << j) + 1][j]);
}

void solve() {
    int n;
    cin >> n;
    map<int, vector<int>> mp;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i], mp[arr[i]].push_back(i);
    }
    int q;
    cin >> q;

    int l, r;
    buildSparse(n);
    while (q--) {
        cin >> l >> r;
        l--, r--;

        int ans = r - l + 1;
        int GCD = query2(l, r);
        int x = upper_bound(mp[GCD].begin(), mp[GCD].end(), r) - mp[GCD].begin();
        x -= lower_bound(mp[GCD].begin(), mp[GCD].end(), l) - mp[GCD].begin();
        cout << ans - x << '\n';
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
