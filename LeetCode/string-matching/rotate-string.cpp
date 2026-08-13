class Solution {
public:
    bool rotateString(string s, string goal) {
        string a=s+s;
        if(a.contains(goal)){
            return true;
        }
        else{
            return false;
        }
    }
};