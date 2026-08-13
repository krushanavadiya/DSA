class Solution {
public:
    int minOperations(string s) {
        int count=0;
        int n = s.size();
        for(int i=0; i<s.size(); i++){
            if(s[i]-'0'!= (i%2==0)){
                count++;
            }
        }

        return min(count,n-count);
    }
};