#include <bits/stdc++.h>

using namespace std;

#define int long long
const int N = 2e5 + 10;
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
    return max(mx[l][j], mx[r - (1 << j) + 1][j]);
}


void solve() {
    int n, m;
    cin >> n;

    for (int i = 0; i < n; i++)cin >> arr[i];
    buildSparse(n);

    cin >> m;
    vector<int> suff(n + 2,0);

    for (int i=0, p, s; i < m; i++)
        cin >> p >> s, suff[s] = max(suff[s], p);

    for (int i = n - 1; i >= 0; i--)
        suff[i] = max(suff[i], suff[i + 1]);

    int ans = 0;
    for (int i = 0; i < n;) {
        ans++;
        int st = i, end = n - 1, mid, res = -1;
        while (st <= end) {
            mid = (st + end) >> 1;
            bool valid = (query2(i, mid) <= suff[mid - i + 1]);
            if (valid)
                st = mid + 1, res = mid;
            else
                end = mid - 1;
        }
        if (res == -1)
            return void(cout << -1 << '\n');

        i = res + 1;
    }
    cout << ans << '\n';
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
