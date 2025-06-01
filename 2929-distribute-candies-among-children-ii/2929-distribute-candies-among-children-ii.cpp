class Solution {
public:
    long long nCk(int n, int k) {
        if (k < 0 || k > n) return 0;
        long long res = 1;
        for (int i = 1; i <= k; ++i) {
            res *= (n - i + 1);
            res /= i;
        }
        return res;
    }

    long long distributeCandies(int n, int limit) {
        long long total = 0;
        for (int k = 0; k <= 3; ++k) {
            long long sign = (k % 2 == 0) ? 1 : -1;
            int remaining = n - (limit + 1) * k;
            if (remaining < 0) continue;
            total += sign * nCk(3, k) * nCk(remaining + 2, 2);
        }
        return total;
    }
};
