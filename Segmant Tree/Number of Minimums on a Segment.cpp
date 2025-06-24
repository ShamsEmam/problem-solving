#include <bits/stdc++.h>

using namespace std;

#define int long long
const int N = 1e5 + 10;
pair<int, int> tree[N * 4];
int arr[N];

void buildSegment(int node, int l, int r) {
    
    if (l == r) {
        tree[node] = {arr[l], 1};
        return;
    }
    
    int mid = (l + r) / 2;
    buildSegment(node * 2, l, mid);
    buildSegment(node * 2 + 1, mid + 1, r);
    
    auto left = tree[node * 2],
    right = tree[node * 2 + 1];
    
    if (left.first < right.first)
        tree[node] = left;
    else if (right.first < left.first)
        tree[node] = right;
    else
        tree[node] = {left.first, left.second + right.second};
}

void update(int node, int l, int r, int idx, int NewVal) {
    if (l == r) {
        tree[node] = {NewVal, 1};
        return;
    }
    int mid = (l + r) / 2;
    
    if (idx <= mid)
        update(node * 2, l, mid, idx, NewVal);
    else
        update(node * 2 + 1, mid + 1, r, idx, NewVal);
    
    auto left = tree[node * 2],
    right = tree[node * 2 + 1];
    
    if (left.first < right.first)
        tree[node] = left;
    else if (right.first < left.first)
        tree[node] = right;
    else
        tree[node] = {left.first, left.second + right.second};
}

pair<int, int> query(int node, int l, int r, int start, int end) {
    
    if (start > r || end < l)
        return {1e9, 0};
    if (l >= start && r <= end)
        return tree[node];
    int mid = (l + r) / 2;
    auto leftVal = query(node * 2, l, mid, start, end);
    auto rightVal = query(node * 2 + 1, mid + 1, r, start, end);
    if (leftVal.first < rightVal.first)
        return leftVal;
    else if (rightVal.first < leftVal.first)
        return rightVal;
    else
        return {leftVal.first, leftVal.second + rightVal.second};
}

void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)cin >> arr[i];

    buildSegment(1, 0, n - 1);
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int idx, nVal;
            cin >> idx >> nVal;
            update(1, 0, n - 1, idx, nVal);
        } else {
            int l, r;
            cin >> l >> r;
            auto res = query(1, 0, n - 1, l, r - 1);
            cout << res.first << " " << res.second << "\n";
        }
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
