class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        long long sum = 0, maxSum = 0;
        int n = nums.size();

        for (int i = 0; i < k && i < n; ++i) {
            sum += nums[i];
            freq[nums[i]]++;
        }

        if (freq.size() == k) maxSum = sum;

        for (int i = k; i < n; ++i) {
            sum += nums[i];
            freq[nums[i]]++;
            sum -= nums[i - k];
            freq[nums[i - k]]--;
            if (freq[nums[i - k]] == 0)
                freq.erase(nums[i - k]);

            if (freq.size() == k)
                maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};
