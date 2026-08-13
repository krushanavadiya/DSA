class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0, j=0;
        unordered_map<int, int> fq;
        int ans=0;

        while(i<n){
            fq[nums[i]]++;

            while(fq[nums[i]]>k){
                fq[nums[j]]--;
                j++;
            }

            ans=max(ans, i-j+1);
            i++;
        }

        return ans;
    }
};