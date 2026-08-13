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
        
        // Check if we've reached the end
        if (i == n) {
            return 0;
        }
        
        // Step 2: Check for sign
        int sign = 1;
        if (s[i] == '+') {
            i++;
        } else if (s[i] == '-') {
            sign = -1;
            i++;
        }
        
        // Step 3: Read digits and convert
        long res = 0;
        while (i < n && s[i]>='0' && s[i]<='9') {
            int digit = s[i] - '0';
            res = res * 10 + digit;
            
            if (sign * res <= min) {
                return min;
            }
            if (sign * res >= max) {
                return max;
            }
            
            i++;
        }
        
        // Step 4: Apply sign and return
        return (int)(res * sign);
    }
};