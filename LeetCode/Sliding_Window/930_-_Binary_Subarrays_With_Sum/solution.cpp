class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        unordered_map<int, int> fq;
        int ans=0;
        int pref=0;
        fq[0]=1;
        for(int i=0; i<n; i++){
            pref+=nums[i];
            ans+=fq[pref-goal];
            fq[pref]++;
        }

        return ans;
    }
};