class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>mp;

        for(int i : nums)
        {
            mp[i]++;
        }
        priority_queue<pair<int,int> , vector<pair<int,int>> ,greater<pair<int,int>>>pq;
        for(auto iter : mp)
        {
           pq.push({iter.second , (-iter.first)});
        }
        
        vector<int>ans;
        while(!pq.empty())
        {
           auto ele = pq.top();
           pq.pop();

           
           for(int i = 0 ; i < ele.first ;i++)
           {
               ans.push_back(-(ele.second));
           }
        }
        return ans;
    }
};