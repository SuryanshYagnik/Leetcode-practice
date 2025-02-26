class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> v;
        int start = 0;
        solve(nums, start, v);
        return v;
    }

    void solve(vector<int>& nums, int start, vector<vector<int>>& v) {
        if (start == nums.size()) {
            v.push_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            swap(nums[start], nums[i]); 
            solve(nums, start + 1, v);  
            swap(nums[start], nums[i]);
        }
    }
};
