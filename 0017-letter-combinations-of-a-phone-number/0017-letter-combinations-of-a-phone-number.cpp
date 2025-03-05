class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.length() == 0) {
            return ans;
        }

        map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        solve(digits, 0, "", mp, ans);
        return ans;
    }

    void solve(string &digits, int index, string temp, map<char, string> &mp, vector<string> &ans) {
        if (index == digits.length()) {  
            ans.push_back(temp);
            return;
        }

        // Get the current digit
        char digit = digits[index];
        string letters = mp[digit];

        // Loop through all characters mapped to the digit
        for (char letter : letters) {
            solve(digits, index + 1, temp + letter, mp, ans); 
        }
    }
};
