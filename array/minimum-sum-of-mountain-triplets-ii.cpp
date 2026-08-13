class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> nextMin(n);
        nextMin[n-1]=nums[n-1];
        for(int i=n-2; i>=0; i--){
            nextMin[i]=min(nextMin[i+1], nums[i]);
        }

        vector<int> prevMin(n);
        prevMin[0]=nums[0];
        for(int i=1; i<n; i++){
            prevMin[i]=min(prevMin[i-1], nums[i]);
        }

        long long ans=INT_MAX;
        for(int i=1; i<n-1; i++){
            if(nextMin[i]<nums[i] && prevMin[i]<nums[i]){
                long long val=(long long)(nextMin[i]+prevMin[i]+nums[i]);
                ans=min(ans, val);
            }
            
        }

        if(ans==INT_MAX) return -1;
        else return ans;
    }
};