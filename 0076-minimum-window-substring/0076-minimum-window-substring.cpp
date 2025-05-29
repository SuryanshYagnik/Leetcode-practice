class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mpp;
        for (char c : t) mpp[c]++;

        int count = mpp.size();
        int i = 0, j = 0;
        int minLen = INT_MAX;
        int start = 0;

        while (j < s.size()) {
            if (mpp.find(s[j]) != mpp.end()) {
                mpp[s[j]]--;
                if (mpp[s[j]] == 0) count--;
            }

            while (count == 0) {
                if (j - i + 1 < minLen) {
                    minLen = j - i + 1;
                    start = i;
                }

                if (mpp.find(s[i]) != mpp.end()) {
                    mpp[s[i]]++;
                    if (mpp[s[i]] > 0) count++;
                }
                i++;
            }

            j++;
        }

        return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
    }
};
