class Solution {
public:
    unordered_map<int, unordered_map<int, int>> memo;

    int solve(int k, int n) {
        if (k == 1) return n;
        if (n == 0) return 0;

        if (memo[k][n]) return memo[k][n];

        int low = 1, high = n, result = n;
        while (low <= high) {
            int mid = (low + high) / 2;
            int broken = solve(k - 1, mid - 1);   
            int notBroken = solve(k, n - mid);     
            int temp = 1 + max(broken, notBroken); 
            if (broken > notBroken) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }

            result = min(result, temp);
        }

        return memo[k][n] = result;
    }

    int superEggDrop(int k, int n) {
        return solve(k, n);
    }
};
