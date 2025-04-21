class Solution {
public:
    vector<vector<int>> dp;

    bool isPalindrome(const string &s, int i, int j) {
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }

    int solve(string &s, int i, int n) {
        if (i == n) return 0;

        if (dp[i][n] != -1) return dp[i][n];

        int minCuts = INT_MAX;
        for (int j = i; j < n; j++) {
            if (isPalindrome(s, i, j)) {
                int cuts = 1 + solve(s, j + 1, n);
                minCuts = min(minCuts, cuts);
            }
        }

        return dp[i][n] = minCuts;
    }

    int minCut(string s) {
        int n = s.length();
        dp.resize(n + 1, vector<int>(n + 1, -1));
        return solve(s, 0, n) - 1;
    }
};
