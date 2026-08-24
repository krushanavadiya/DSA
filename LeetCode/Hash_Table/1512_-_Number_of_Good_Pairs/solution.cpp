class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n=nums.size();

        unordered_map<int, int> fq;
        int ans=0;

        for(int i=0; i<n; i++){
            ans+=fq[nums[i]];
            fq[nums[i]]++;
        }

        return ans;
    }
};