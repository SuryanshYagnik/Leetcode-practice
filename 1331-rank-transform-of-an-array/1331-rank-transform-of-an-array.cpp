class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mpp;
        vector<int> a = arr;
        vector<int> ans(n);
        int j = 1;
        sort(a.begin(), a.end());
        
        for(int i = 0; i < n; i++) {
            if(mpp.find(a[i]) == mpp.end()) {
                mpp[a[i]] = j;
                j++;
            }
        }
        
        for (int i = 0; i < n; i++) {
            ans[i] = mpp[arr[i]];
        }
        
        return ans;
    }
};
