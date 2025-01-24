class Solution {
public:
    int minBitFlips(int start, int goal) {
        int n = start^goal;
        int x = __builtin_popcount(n);
        return x;
        
    }
};