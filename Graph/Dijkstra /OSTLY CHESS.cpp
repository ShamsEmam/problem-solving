#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(s) s.begin(), s.end()
#define sz(s) (int)(s).size()
int const N = 1e3 + 5;
int const oo = 1e15;
int dist[8][8];

int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};

struct node {
    int x1, y1, cost;

    node(int _x1, int _y1, int _x2) : x1(_x1), y1(_y1), cost(_x2) {}

    node() {}
};

struct cmp {
    bool operator()(node &a, node &b) {
        return a.cost > b.cost;
    }
};

bool valid(int x, int y) {
    return x >= 0 && x < 8 && y >= 0 && y < 8 ;
}

int Dij(int xstart, int ystart, int Xend, int Yend) {
    for (int i = 0; i <= 8; i++)
        for (int j = 0; j <= 8; j++)
            dist[i][j] = oo;
    priority_queue<node, vector<node>, cmp> pq;
    pq.push(node(xstart, ystart, 0));
    dist[xstart][ystart] = 0;

    while (sz(pq)) {
        node p = pq.top();
        pq.pop();

        if (p.cost > dist[p.x1][p.y1])continue;
        if (p.x1 == Xend && p.y1 == Yend)return dist[p.x1][p.y1];

        for (int i = 0; i < 8; ++i) {

            int nx = p.x1 + dx[i], ny = p.y1 + dy[i];
            if (!valid(nx,ny))continue;
            ll new_cost = nx * p.x1 + ny * p.y1+p.cost;

            if (new_cost < dist[nx][ny]) {
                dist[nx][ny] = new_cost;
                pq.push(node(nx, ny, new_cost));
            }
        }
    }
    return dist[Xend][Yend];
}

void clear() {
    memset(dist, 0, sizeof dist);
}

void solve() {
    int a,b,c,d;
    while(cin >> a >> b >> c >> d) {
        cout << Dij(a,b,c,d) << "\n";
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

int main() {
    setupIO();
    speed();
    int t = 1;
//    cin >> t;
    while (t--) solve();
    return 0;
}
