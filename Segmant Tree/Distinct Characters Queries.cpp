#include <bits/stdc++.h>

using namespace std;

#define int long long
const int N = 1e5 + 10;
int tree[N * 4], arr[N];
string s;

//build Segment tree
void buildSegment(int node, int l, int r, const string &s) {
    //base case
    if (l == r) {
        tree[node] = 1LL << (s[l] - 'a');  // bitmask
         return;
    }
    //mid point
    int mid = (r + l) / 2;

    //left node
    buildSegment(node * 2, l, mid, s);             // left child

    //Right node
    buildSegment(node * 2 + 1, mid + 1, r, s);     // right child

    // node ->marge (left child,right child)
    tree[node] = tree[node * 2] | tree[node * 2 + 1];
}

//update
//idx -> index i need to updated, {r,l} ->rang ,node->cur idx
void update(int node, int l, int r, int idx, char NewVal) {

    //base case
    if (l == r) {
        tree[node] = 1LL << (NewVal - 'a');  // bitmask
        return;
    }

    int mid = (l + r) / 2;

    //go left[l,mid]
    if (idx <= mid)
        update(node * 2, l, mid, idx, NewVal);

        //go right
    else
        update(node * 2 + 1, mid + 1, r, idx, NewVal);

    // node ->marge (left child,right child)
    tree[node] = tree[node * 2] | tree[node * 2 + 1];
}


// Rang Query or node l, r, start ,end
int query(int node, int l, int r, int start, int end) {
    //base case
    //out of rang
    if (start > r || end < l)
        return 0;
    //in rang
    if (l >= start && r <= end)
        return tree[node];
    int mid = (l + r) >> 1;

    // left l,mid
    int leftVal = query(node * 2, l, mid, start, end);

    //right mid+1 ,r
    int rightVal = query(node * 2 + 1, mid + 1, r, start, end);
    return leftVal | rightVal;
}

void solve() {
    cin >> s;
    int n = s.size();
    buildSegment(1, 0,n - 1, s);
    int q;
    cin >> q;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            char c;
            int idx;
            cin >> idx >> c;
            idx--;
            update(1, 0, n - 1, idx, c);
        } else {
            int l, r;
            cin >> l >> r;
            l--, r--;
            int mask = query(1, 0, n - 1, l, r);
            cout << __builtin_popcountll(mask) << '\n';;
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
