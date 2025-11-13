#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(s) s.begin(), s.end()
#define sz(s) (int)(s).size()

const int N = 1e3 + 5;
int n, m, short_path;
char s[N][N];
string ans = "NO";
vector<pair<int, int>> adj[N];

struct node {
    int x, y, cost;

    node(int X, int Y, int C) : x(X), y(Y), cost(C) {}
};

bool valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && s[x][y] == '.' || s[x][y] == 'B';
}

void bfs(int startX, int startY, int endX, int endY) {
    queue<node> q;
    q.push(node(startX, startY, 0));
    while (!q.empty()) {
        node p = q.front();
        q.pop();
        if (p.x == endX && p.y == endY) {
            ans = "YES";
            short_path = p.cost;
            return;
        }
        if (valid(p.x, p.y - 1))q.push(node(p.x, p.y - 1, p.cost + 1)), s[p.x][p.y - 1] = 'L';
        if (valid(p.x + 1, p.y))q.push(node(p.x + 1, p.y, p.cost + 1)), s[p.x + 1][p.y] = 'D';
        if (valid(p.x - 1, p.y))q.push(node(p.x - 1, p.y, p.cost + 1)), s[p.x - 1][p.y] = 'U';
        if (valid(p.x, p.y + 1))q.push(node(p.x, p.y + 1, p.cost + 1)), s[p.x][p.y + 1] = 'R';
    }
}

void solve() {
    cin >> n >> m;
    int startX = 0, startY = 0, endX = 0, endY = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> s[i][j];
            if (s[i][j] == 'A')startX = i, startY = j;
            if (s[i][j] == 'B')endX = i, endY = j;
        }
    }
    bfs(startX, startY, endX, endY);
    cout << ans << '\n';
    if (ans == "YES") {
        cout << short_path << '\n';
        int i = endX, j = endY;
        string path;
        while (i != startX || j != startY) {
            path += s[i][j];
            char c = s[i][j];
            if (c == 'L')j++;
            else if (c == 'R')j--;
            else if (c == 'U')i++;
            else if (c == 'D')i--;
        }
        reverse(all(path));
        cout << path << '\n';
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
