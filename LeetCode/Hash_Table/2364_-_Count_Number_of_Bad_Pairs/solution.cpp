class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n=nums.size();

        unordered_map<int, long long> fq;

        for(int i=0; i<n; i++){
            fq[nums[i]-i]++;
        }

        long long good=0;

        for(auto it: fq){
            if(it.second>1){
                good+=(it.second*(it.second-1)/2);
            }
        }

        return n*(n-1)/2-good;
    }
};