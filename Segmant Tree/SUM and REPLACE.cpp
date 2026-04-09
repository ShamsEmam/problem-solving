#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define int long long
#define ld long double
#define all(s) s.begin(), s.end()
#define sz(s) (int)(s).size()
ll const oo = 1e15;
int const N = 1e6 + 5;
int d[N];

void pre() {
    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j += i) {
            d[j]++;
        }
    }
}

struct Node {
    int val = 0;

    Node() {}

    Node(int val) {
        this->val = val;
    }
};

struct SegTree {
#define mid ((lx+rx)/2)
#define lf (2*x+1)
#define rt (2*x+2)
#define neutral 0
    vector<Node> seg;
    int n;

    void init(vector<int> &v) {
        n = sz(v);
        seg.assign(4 * n, {neutral});
        build(v, 0, 0, n - 1);
    }

    Node mrg(const Node &Lf, const Node &Rt) {
        return {Rt.val + Lf.val};
    }

    void build(vector<int> &v, int x, int lx, int rx) {
        if (lx == rx) {
            seg[x] = Node(v[lx]);
            return;
        }
        build(v, lf, lx, mid);
        build(v, rt, mid + 1, rx);
        seg[x] = mrg(seg[lf], seg[rt]);
    }

    void update(int idx, int val, int x, int lx, int rx) {
        if (lx == rx) {
            seg[x] = {val};
            return;
        }
        if (idx <= mid)
            update(idx, val, lf, lx, mid);
        else
            update(idx, val, rt, mid + 1, rx);

        seg[x] = mrg(seg[lf], seg[rt]);
    }

    void update(int idx, int val) {
        return update(idx, val, 0, 0, n - 1);
    }

    Node query(int lq, int rq, int x, int lx, int rx) {
        if (rx < lq || lx > rq)
            return {0};
        if (lx >= lq && rx <= rq)
            return seg[x];


        return mrg(query(lq, rq, lf, lx, mid),
                   query(lq, rq, rt, mid + 1, rx));
    }

    Node query(int lq, int rq) {
        return query(lq, rq, 0, 0, n - 1);
    }

#undef mid
#undef lf
#undef rt
#undef neutral
};

void solve() {
    set<ll> valid;
    pre();
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    SegTree st;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        if (d[v[i]] != v[i])
            valid.insert(i);
    }
    st.init(v);
    int op, l, r;
    while (q--) {
        cin >> op;
        if (op == 1) {
            cin >> l >> r;
            l--, r--;
            auto it = valid.lower_bound(l);
            while (it != valid.end() and *it <= r) {
                v[*it] = d[v[*it]];
                st.update(*it, v[*it]);
                if (d[v[*it]] == v[*it]) {
                    it = valid.erase(it);
                } else
                    ++it;
            }

        } else {
            cin >> l >> r;
            cout << st.query(--l, --r).val << '\n';
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
//    cout << fixed << setprecision(15);
//    cin >> t;
    while (t--) solve();
    return 0;
}
