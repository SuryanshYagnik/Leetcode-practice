class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector <int> small;
        vector <int> large;
       
        int count = 0;
        for(int i=0; i<nums.size();i++){
            if(nums[i]==pivot){
                count++;
            }
            else if(nums[i]<pivot){
                small.push_back(nums[i]);
            }
            else{
                large.push_back(nums[i]);
            }
        }
        
        for (int i = 0; i < count; i++) {
            small.push_back(pivot);
        }
        
        small.insert(small.end(), large.begin(), large.end());
        return small;
    }
};