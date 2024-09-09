class Solution {
public:
    string largestOddNumber(string num) {
        int idx = num.length() - 1;

        // num[idx] - '0' converts the number character into an integer
        // & 1 checks whether or not the number is odd
        while (idx >= 0 && ((num[idx] - '0') & 1) == 0) --idx;

        // return the substring we found based on the index we stopped at
        return num.substr(0, idx + 1);
    }
};