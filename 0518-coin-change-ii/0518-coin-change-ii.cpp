class Solution {
long long mod = 1e11+7;
public:
    int change(int amount, vector<int>& coins) {
        vector<long long> dp(amount + 1, 0);
        dp[0] = 1;

        for (int coin : coins) {
            for (int x = coin; x <= amount; ++x) {
                dp[x] += dp[x - coin]%mod;
            }
        }

        return dp[amount];
    }
};
