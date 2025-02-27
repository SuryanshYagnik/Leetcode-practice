class Solution {
public:
    bool isPalindrome(string s) {
        return s == string(s.rbegin(), s.rend());
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> currentPartition;
        solve(s, 0, currentPartition, result);
        return result;
    }

    void solve(string &s, int start, vector<string> &currentPartition, vector<vector<string>> &result) {
        if (start == s.length()) {
            result.push_back(currentPartition);
            return;
        }

        for (int i = start; i < s.length(); i++) {
            string substring = s.substr(start, i - start + 1);
            if (isPalindrome(substring)) {
                currentPartition.push_back(substring);
                solve(s, i + 1, currentPartition, result);
                currentPartition.pop_back();
            }
        }
    }
};
