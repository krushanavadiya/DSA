class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        auto total=0, nonZ=0;

        for(int i=0; i<n; i++){
            nonZ|=nums[i]>0;
            total^=nums[i];
        }

        return nonZ*(n-!total);
    }
};

