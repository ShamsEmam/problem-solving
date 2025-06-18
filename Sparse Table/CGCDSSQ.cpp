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
            mx[j][i] = gcd(mx[j][i - 1], mx[j + (1 << (i - 1))][i - 1]);
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
    return gcd(mx[l][j], mx[r - (1 << j) + 1][j]);
}

void solve() {
    int n, q, x;
    cin >> n;
    for (int i = 0; i < n; i++)cin >> arr[i];

    cin >> q;
    buildSparse(n);

    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int GCD = arr[i], st, ed, mid, res, idx = i;
        while (idx < n) {
            st = idx, ed = n - 1, res=0;
            while (st <= ed) {
                mid = (st + ed) >> 1;
                if (query2(i, mid) == GCD)
                    st = mid + 1, res = mid;
                else
                    ed = mid - 1;
            }
            mp[GCD] += (res - idx + 1);
            idx = res + 1;
            GCD = query2(i, idx);
        }
    }

    while (q--)
        cin >> x, cout << mp[x] << '\n';

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
