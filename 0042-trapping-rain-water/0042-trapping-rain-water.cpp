class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>nge(n), pge(n);
        pge[0] = height[0];
        nge[n-1] = height[n-1];
        for(int i=1;i<n;i++){
            pge[i] = max(height[i], pge[i-1]);
        }
        for(int i = n-2;i>=0;i--){
            nge[i] = max(height[i], nge[i+1]);
        }
        int area = 0;

        for(int i=0;i<n;i++){
            area = area + (min(pge[i], nge[i]) - height[i]);
        }
        return area;
    }
};