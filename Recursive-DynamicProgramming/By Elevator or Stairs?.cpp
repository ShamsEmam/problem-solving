#include <bits/stdc++.h>

using namespace std;

#define int long long
const int N = 200005;
int n,c, dp[N][2],a[N],b[N];

int REC(int idx,int flag) {
    if (idx == 1)
        return (flag?c:0);

    int &val=dp[idx][flag];
    if (~val)
        return val;

    if (flag){
        val= min(REC(idx-1,1), REC(idx-1,0)+c)+b[idx];
    }
    else{
        val= min(REC(idx-1,0), REC(idx-1,1))+a[idx];
    }
    return val;
}

void solve() {
    cin >> n>>c;

    for (int i = 2; i <= n; ++i) cin >> a[i];
    for (int i = 2; i <= n; ++i) cin >> b[i];


    memset(dp, -1, sizeof(dp));

    for (int i = 1; i <= n; ++i) {
        cout<<min(REC(i,0), REC(i,1))<<" ";
    }
}


void speed() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
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
    while (t--) {
        solve();
    }
    return 0;
}
