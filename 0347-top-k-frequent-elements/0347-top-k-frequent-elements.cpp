class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map <int,int> mpp;
    vector <int>  ans;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> mh;
    for(int i = 0; i<n; i++){
        mpp[nums[i]]++;
    }

for (auto it = mpp.begin(); it != mpp.end(); ++it) {

    mh.push({it->second, it->first});


        if(mh.size() > k){
            mh.pop();
        }
    }

    while(mh.size() > 0){
        ans.push_back(mh.top().second);
        mh.pop();
    }
     return ans;   
    }
};