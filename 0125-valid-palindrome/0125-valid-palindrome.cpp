class Solution {
public:

    string s; //declaring string globally

    bool palindromeCheck( int l,int r){
        //base condition
        if(l>=r)
            return true;
        //If the character is not alphanumeric then move the left forward
        if(!isalnum(s[l])){
            return palindromeCheck(l+1,r);
        }
        //If the character is not alphanumeric then move the right backward
        else if(!isalnum(s[r])){
            return palindromeCheck(l,r-1);
        }
        //checking palindrome condition
        else if(toupper(s[l])==toupper(s[r])){
            return palindromeCheck(l+1,r-1);
        }
        //if the characters are not equal then return false
        else{
            return false;
        }
    }
    bool isPalindrome(string ques) {

        s = ques;
        return palindromeCheck(0,s.length()-1);
    }
};