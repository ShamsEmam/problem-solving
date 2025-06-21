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
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)cin >> arr[i];


    for (int i = 0; i < n - 1; ++i) {
        arr[i] = abs(arr[i] - arr[i + 1]);
    }

    buildSparse(n - 1);

    int st = 1, end = n - 1, res = 0, mid;
    while (st <= end) {
        mid = (st + end) >> 1;

        bool valid = false;
        for (int i = 0; i + mid - 1 < n - 1; ++i) {
            valid |= (query2(i, i + mid - 1) > 1);
        }
        if (valid)
            st = mid + 1, res = mid;
        else
            end = mid - 1;
    }
    cout << res + 1 << '\n';
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
