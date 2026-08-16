class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();

        int j=0;
        int len=0;
        unordered_map<int, int> fq;

        for(int i=0; i<n; i++){
            fq[nums[i]]++;

            while(fq[0]>1){
                fq[nums[j]]--;
                j++;
            }

            len=max(len, i-j);
        }

        return len;
    }
};