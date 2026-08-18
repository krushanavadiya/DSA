class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int, int> fq;
        int ans=-1;

        for(int i=0; i<=n-k; i++){
            unordered_set<int> curr;

            for(int j=i; j<k+i; j++){
                curr.insert(nums[j]);
            }

            for(int it: curr){
                fq[it]++;
            }
        }

        for(auto it: fq){
            if(it.second==1){
                ans=max(ans, it.first);
            }
        }

        return ans;
    }
};