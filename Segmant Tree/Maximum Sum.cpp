#include <bits/stdc++.h>

using namespace std;

struct Node {
    pair<int, int> mx;
};

struct SegmentTree {

    vector<Node> tree;
    Node neutral = Node({{INT_MIN, INT_MIN}});

    SegmentTree(int n) {
        int sz = 1;
        while (sz < n) {
            sz *= 2;
        }
        tree = vector<Node>(2 * sz);
    }

    Node single(int idx, int val) {
        Node leaf;
        leaf.mx = {val, 0};
        return leaf;
    }

    Node marge(Node a, Node b) {
        Node ret;
        vector<int> v = {a.mx.first, a.mx.second, b.mx.first, b.mx.second};
        sort(v.rbegin(), v.rend());
        ret.mx = {v[0], v[1]};
        return ret;
    }

    void build(int node, int l, int r, vector<int> &v) {
        if (l == r) {
            tree[node] = single(l, v[l]);
            return;
        }
        int mid = (l + r) >> 1;
        build(2 * node, l, mid, v);
        build(2 * node + 1, mid + 1, r, v);
        tree[node] = marge(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int idx, int NewVal) {
        if (l == r && l == idx) {
            tree[node] = single(idx, NewVal);
            return;
        }
        int mid = (l + r) >> 1;
        if (idx <= mid)
            update(2 * node, l, mid, idx, NewVal);
        else
            update(2 * node + 1, mid + 1, r, idx, NewVal);
        tree[node] = marge(tree[2 * node], tree[2 * node + 1]);
    }

    Node query(int node, int s, int e, int l, int r) {
        if (r < s || l > e)
            return neutral;
        if (s >= l && e <= r)
            return tree[node];
        int mid = (s + e) >> 1;
        Node left = query(2 * node, s, mid, l, r);
        Node right = query(2 * node + 1, mid + 1, e, l, r);
        return marge(left, right);
    }

};

void solve() {

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    SegmentTree st(n);
    st.build(1, 0, n - 1, v);

    int q, idx, nVal, l, r;
    cin >> q;
    char op;
    while (q--) {
        cin >> op;
        if (op == 'U') {
            cin >> idx >> nVal;
            idx--;
            st.update(1, 0, n - 1, idx, nVal);
        } else {
            cin >> l >> r;
            l--, r--;
            auto ans = st.query(1, 0, n - 1, l, r).mx;
            cout << ans.first + ans.second << '\n';
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
