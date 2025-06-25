#include <bits/stdc++.h>

using namespace std;


struct Node {
    int val=0;
};

struct SegmentTree {
    vector<Node> tree;
    Node neutral = Node({0});

    SegmentTree(int n) {
        int sz = 1;
        while (sz < n) {
            sz *= 2;
        }
        tree = vector<Node>(2 * sz);
    }

    //convert value to node in tree
    Node single(int idx, int val) {
        Node leaf;
        leaf.val = val;
        return leaf;
    }

    Node marge(Node a, Node b, bool flag) {
        Node ret;
        if (!flag) {
            ret.val = (a.val ^ b.val);
        } else {
            ret.val = a.val | b.val;
        }
        return ret;
    }

    void build(int node, int l, int r, vector<int> &v, bool status) {
        if (l == r) {
            tree[node] = single(l, v[l]);
            return;
        }
        int mid = (l + r) >> 1;
        build(2 * node, l, mid, v, !status);
        build(2 * node + 1, mid + 1, r, v, !status);
        tree[node] = marge(tree[node * 2], tree[node * 2 + 1], status);
    }

    void update(int node, int l, int r, int idx, int NewVal, bool status) {
        if (l == r && l == idx) {
            tree[node] = single(idx, NewVal);
            return;
        }
        int mid = (l + r) >> 1;
        if (idx <= mid)
            update(2 * node, l, mid, idx, NewVal, !status);
        else
            update(2 * node + 1, mid + 1, r, idx, NewVal, !status);
        tree[node] = marge(tree[2 * node], tree[2 * node + 1], status);
    }

//    Node query(int node, int s, int e, int l, int r) {
//        if (r < s || l > e)
//            return neutral;
//        if (s >= l && e <= r)
//            return tree[node];
//        int mid = (s + e) >> 1;
//        Node left = query(2 * node, s, mid, l, r);
//        Node right = query(2 * node + 1, mid + 1, e, l, r);
//        return marge(left, right);
//    }

};

void solve() {

    int n, q;
    cin >> n >> q;
    vector<int> v(1 << n);
    for (int i = 0; i < (1 << n); i++)cin >> v[i];

    SegmentTree st(1 << n);
    bool flag = (n & 1) ? true : false;
    st.build(1, 0, (1 << n) - 1, v, flag);

    int idx, nVal;
    while (q--) {
        cin >> idx >> nVal;
        idx--;
        st.update(1, 0, (1<<n) - 1, idx, nVal, flag);
        cout << st.tree[1].val<<'\n';
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
