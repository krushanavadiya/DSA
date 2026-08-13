class Solution {
public:
    string reversePrefix(string s, int k) {
        string s1=s;;
        reverse(s1.begin(),s1.begin()+k);

        return s1;
        
    }
};