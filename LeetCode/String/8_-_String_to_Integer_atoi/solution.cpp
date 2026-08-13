class Solution {
public:
    int myAtoi(string s) {
        if (s == "" || s.size() == 0) {
            return 0;
        }
        
        // Constants for 32-bit signed integer range
        int max = INT_MAX;
        int min = INT_MIN;
        
        int i = 0;
        int n = s.size();
        
        // Step 1: Skip leading whitespace
        while (i < n && s[i] == ' ') {
            i++;
        }
        

