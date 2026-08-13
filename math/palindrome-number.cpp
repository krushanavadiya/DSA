class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        
        string str=to_string(x);
        string revStr=str;
        reverse(str.begin(), str.end());

        if(str==revStr){
            return true;
        }

        return false;
    }
};