class Solution {
public:
    int Summ(vector<int>nums,int divisor,int treshold){
        int n = nums.size();
        int Sum=0;
        for(int i =0;i<n;i++){
            Sum += ceil((double)nums[i]/(double)divisor);
        }
        return Sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int low = 1, high = *max_element(nums.begin(), nums.end());
        if(n>threshold){return -1;}

        while(low<=high){
            int mid = low + (high - low)/2;
            int Sum = Summ(nums,mid,threshold);
            if(Sum>threshold){
                low = mid+1;
            }
            else{
                high = mid-1;
                
            }
            
        }
        return low;
    }
};