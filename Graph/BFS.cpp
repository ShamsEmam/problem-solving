#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ld long double
int const N = 1e3 + 10, M = 1e7 + 5;

int n, m, cnt;
char arr[N][N];
bool vst[N][N];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void BFS(int x, int y) {
    queue<pair<int, int> > q;
    q.push({x, y});
    vst[x][y] = true;
    while (!q.empty()) {
        auto [px, py] = q.front();
        q.pop();

        if (arr[px][py] == 'F') cnt++;

        for (int i = 0; i < 4; i++) {
            int nx = px + dx[i];
            int ny = py + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (arr[nx][ny] != 'X' and !vst[nx][ny]) {
                    vst[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    cnt = 0;
    memset(vst, false, sizeof vst);

    pair<int, int> start;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> arr[i][j];
            if (arr[i][j] == 'Y')
                start = {i, j};
        }
    }
    BFS(start.first, start.second);
    cout << cnt << "\n";
}


void speed() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

signed main() {
    speed();
    freopen("pub2d.in", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
