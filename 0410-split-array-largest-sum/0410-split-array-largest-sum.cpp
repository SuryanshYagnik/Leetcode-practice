class Solution {
public:
        int countk(vector<int>arr, int limit){
            int n = arr.size();
            int countk = 1;
            long long Sum  = 0;
            for(int i = 0; i<n; i++){
                if(Sum + arr[i] <= limit ){
                    Sum += arr[i];
                }
                else{
                    countk++;
                    Sum = arr[i];
                }
            
            }
            return countk;;
        }
    int splitArray(vector<int>& arr, int k) {
        int n  = arr.size();
        if(k>n){return -1;}
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        while(low<=high){
            int mid = low + (high - low)/2;
            int count = countk(arr,mid);
            if(count > k){
                low = mid+1;
    
            }
            else{
                high = mid-1;
            }
            
        }

return low;
        

    }
};