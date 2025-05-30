class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<int> ans;
        priority_queue<pair<int,int>> mh;
        for(int i = 0; i<n ; i++){
            mh.push({abs(x-arr[i]), arr[i]});
            if(mh.size() > k){
                mh.pop();
            }

        }

        while(mh.size() > 0){
            ans.push_back(mh.top().second);
            mh.pop();
    }
    sort(ans.begin(), ans.end());
    return ans;
        
    }
};

