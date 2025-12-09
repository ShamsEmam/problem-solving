class Solution {
public:
    int countSubstrings(string s) {
        int n = (int) s.size();
        bool isP[n][n];
        //isP is true if substring is palindrome
        for (int i = 0; i < n; ++i) isP[i][i] = true;

        for (int len = 2; len <= n; ++len) {
            for (int l = 0; l + len - 1 < n; ++l) {
                int r = l + len - 1;
                if (l == r - 1)
                    isP[l][r] = s[l] == s[r];
                else
                    isP[l][r] = isP[l + 1][r - 1] && s[l] == s[r];
            }
        }
        int dp[n][n];
        // dp [l][r] no.of palindrome substring from l...r
        memset(dp, 0, sizeof dp);
        for (int i = 0; i < n; i++) dp[i][i] = 1;
        for (int len = 2; len <= n; len++) {
            for (int l = 0; l + len - 1 < n; ++l) {
                int r = len + l - 1;
                dp[l][r] += isP[l][r] + dp[l + 1][r] + dp[l][r - 1] - dp[l + 1][r - 1];
            }
        }
        return dp[0][n - 1];
    }
};
