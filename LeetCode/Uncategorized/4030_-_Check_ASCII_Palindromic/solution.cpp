class Solution {
public:
    bool isPalindromic(string s) {
        string binary="";
        for(int i=0; i<s.size(); i++){
            binary+=bitset<8>(s[i]).to_string();
        }

        int l=0, r=binary.size()-1;

        while(l<=r){
            if(binary[l]==binary[r]){
                l++;
                r--;
            }
            else{
                return false;
            }
        }

        return true;
    }
};

