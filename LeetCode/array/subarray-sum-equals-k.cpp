class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        unordered_map<int, int> fq;

        vector<int> prefix(n);
        prefix[0]=nums[0];

        for(int i=1; i<n; i++){
            prefix[i]=nums[i]+prefix[i-1];
        }

        for(int i=0; i<n; i++){
            if(prefix[i]==k){
                ans++;
            }

            int rem=prefix[i]-k;

            if(fq.find(rem)!=fq.end()){
                ans+=fq[rem];
            }

            fq[prefix[i]]++;
        }

        return ans;
    }
};