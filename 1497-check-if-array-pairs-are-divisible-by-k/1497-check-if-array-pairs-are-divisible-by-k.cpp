class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        for(auto n: arr)
        {
            int rem = n%k;
            rem = (rem+k)%k;
            int op = rem==0?0:k-rem;
            if( auto it = mp.find(op);it!=mp.end())
            {
                if(--it->second==0)
                    mp.erase(it);
            }
            else
                mp[rem]++;

        }
        return mp.size()==0;
    }
};