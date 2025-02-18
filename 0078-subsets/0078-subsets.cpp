class Solution {
public:

    void rec( vector<vector<int>>& results, int index, vector<int>& current, vector<int>& nums){
        if (index==nums.size()){
            results.push_back(current);
            return;
        }

        current.push_back(nums[index]);
        rec(results, index+1, current, nums);
        current.pop_back();
        rec(results, index+1, current, nums);

    }

    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>> results;
       vector<int> current; 
        rec(results, 0, current, nums);
        return results;
    }
};