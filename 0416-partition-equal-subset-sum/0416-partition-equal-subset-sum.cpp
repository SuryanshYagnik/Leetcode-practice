class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        if (sum % 2 != 0) { // Check for odd sum
            return false;
        }
        return subsetSum(nums, sum / 2);
    }

    bool subsetSum(vector<int>& nums, int sum) {
        int n = nums.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }

        for (int i = 1; i <= n; i++) { 
            for (int s = 1; s <= sum; s++) { 
                if (nums[i - 1] <= s) { 
                    dp[i][s] = dp[i - 1][s - nums[i - 1]] || dp[i - 1][s];
                } else {
                    dp[i][s] = dp[i - 1][s];
                }
            }
        }
        return dp[n][sum];
    }
};