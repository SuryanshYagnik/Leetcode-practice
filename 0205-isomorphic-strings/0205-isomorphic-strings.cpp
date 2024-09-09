class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> mpp;
        map<char, char> mppr;

        if (s.length() != t.length()) {
            return false;
        }
        for (int i = 0; i < s.length(); i++) {
            if (mppr[t[i]] != NULL && mppr[t[i]] != s[i]) {
                return false;
            } else {
                mppr[t[i]]=s[i];
            }
            if (mpp[s[i]] == t[i]) {
                continue;
            } else if (mpp[s[i]] == NULL) {
                mpp[s[i]] = t[i];

            } else if (mpp[s[i]] != t[i]) {
                return false;
            }
        }

        return true;

        // array i,2,3,4   arr[0]=1
        // mpp['a']=5;
        // mpp['a']==5 //true
    }
};