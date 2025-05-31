class Solution {
public:
    int distance(const vector<int>& c) {
        int x = c[0], y = c[1];
        return x * x + y * y;
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < n; i++) {
            int dis = distance(points[i]);
            pq.push({dis, i});
            if (pq.size() > k)
                pq.pop();
        }

        vector<vector<int>> ans;
        while (!pq.empty()) {
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        return ans;
    }
};
