class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() == 1) {
            return true ;
        }
        if (s.length() != goal.length()) {
            return false ;
        }

        int count = 0 ;
        while (count < s.length()) {
            s = s.substr(1) + s[0] ;
            if (s == goal) {
                return true ;
            }
            count++ ;
        }
        return false ;
    }
};