class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int, int> fq;
        fq[0]=-1;

        int sum=0;
        for(int i=0; i<n; i++){
            sum+=nums[i];
            int rem=sum%k;

            if(fq.find(rem)!=fq.end()){
                if(i-fq[rem]>=2) return true;
            }
            else{
                fq[rem]=i;
            }
        }

        return false;
    }
};