class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0;
        int ans=0;

        unordered_map<int, int> fq;
        fq[0]=1;
        for(int i=0; i<n; i++){
            sum+=nums[i]%2;
            ans+=fq[sum-k];
            fq[sum]++;
        }

        return ans;
    }
};