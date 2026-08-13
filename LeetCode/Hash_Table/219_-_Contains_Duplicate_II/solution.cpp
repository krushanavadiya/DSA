class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int, int> fq;
        for(int i=0; i<n; i++){

            if(fq.contains(nums[i])){
                int j=fq[nums[i]];
                if(nums[i]==nums[j] && abs(i-j)<=k){
                    return true;
                }
            }
            fq[nums[i]]=i;
        }

        return false;
    }
};

