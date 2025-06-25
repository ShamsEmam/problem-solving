#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 200005; 
int tree[N * 4], arr[N];

void buildSegment(int node, int l, int r) {
    if (l == r) {
        tree[node] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    buildSegment(node * 2, l, mid);
    buildSegment(node * 2 + 1, mid + 1, r);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void update(int node, int l, int r, int idx, int NewVal) {
    if (l == r) {
        tree[node] = NewVal;
        return;
    }
    int mid = (l + r) / 2;
    if (idx <= mid)
        update(node * 2, l, mid, idx, NewVal);
    else
        update(node * 2 + 1, mid + 1, r, idx, NewVal);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int node, int l, int r, int start, int end) {
    if (start > r || end < l)
        return 0;
    if (l >= start && r <= end)
        return tree[node];
    int mid = (l + r) / 2;
    int leftVal = query(node * 2, l, mid, start, end);
    int rightVal = query(node * 2 + 1, mid + 1, r, start, end);
    return leftVal + rightVal;
}

int cnt;

void solve() {
    bool first = true;
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        if (!first) cout << "\n";
        first = false;

        cout << "Case " << ++cnt << ":\n";

        for (int i = 0; i < n; i++) cin >> arr[i];

        buildSegment(1, 0, n - 1);

        string s;
        while (true) {
            cin >> s;
            if (s == "END") break;
            if (s == "S") {
                int idx, val;
                cin >> idx >> val;
                --idx;
                update(1, 0, n - 1, idx, val);
            } else if (s == "M") {
                int l, r;
                cin >> l >> r;
                --l; --r;
                cout << query(1, 0, n - 1, l, r) << "\n";
            }
        }
    }
}

void speed() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

signed main() {
    speed();
    solve();
    return 0;
}
