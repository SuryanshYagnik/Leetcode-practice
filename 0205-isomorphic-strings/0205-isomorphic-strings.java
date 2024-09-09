// Algo Used: Hashing
// TC: O N , SC: O 1 (Since we are using constant 256 values we can treat it as constant space i.e 1)
class Solution {
    public boolean isIsomorphic(String s, String t) {
        if (s.length() != t.length()) return false;

        int[] mapS = new int[256]; // Mapping from characters in s to characters in t
        int[] mapT = new int[256]; // Mapping from characters in t to characters in s

        for (int i = 0; i < s.length(); i++) {
            char c1 = s.charAt(i);
            char c2 = t.charAt(i);

            // If the mapping doesn't match the previous mappings, return false
            if (mapS[c1] != 0 && mapS[c1] != c2 || mapT[c2] != 0 && mapT[c2] != c1) {
                return false;
            }

            // Establish the mapping
            mapS[c1] = c2;
            mapT[c2] = c1;
        }

        return true;
    }
}