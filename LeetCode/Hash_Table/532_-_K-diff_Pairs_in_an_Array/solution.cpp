class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> fq;
        int n=nums.size();

        int ans=0;

        for(int i=0; i<n; i++){
            fq[nums[i]]++;
        }

        for(auto it: fq){
            if(k==0){
                if(it.second>1) ans++;
            }
            else {
                if(fq.contains(it.first+k)) ans++;
            }
        }

        return ans;
    }
};