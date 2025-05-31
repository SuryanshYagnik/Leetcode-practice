class Solution {
public:
    int distance(vector<int> c) {
        int x = c[0], y = c[1];
        return ((x * x) + (y * y));
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        int n = points.size();
        priority_queue<pair<int, vector<int>>> pq;

        for (int i = 0; i < n; i++) {
            int dis = distance(points[i]);
            pq.push({dis, points[i]});
            if (pq.size() > k)
                pq.pop();
        }

        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};