class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        vector<int> nextMax(n);
        nextMax[n-1]=nums[n-1];
        for(int i=n-2; i>=0; i--){
            nextMax[i]=max(nextMax[i+1], nums[i]);
        }

        vector<int> prevMax(n);
        prevMax[0]=nums[0];
        for(int i=1; i<n; i++){
            prevMax[i]=max(prevMax[i-1], nums[i]);
        }

        long long ans=0;
        for(int i=1; i<n-1; i++){
            long long val=(long long)(prevMax[i-1]-nums[i])*nextMax[i+1];
            ans=max(ans, val);
        }

        return ans;
    }
};