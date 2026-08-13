class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();

        if(n==1){
            return nums[0];
        }

        if(n==2){
            return min(nums[1],nums[0]);
        }

        int l=0, r=n-1;
        int ans=INT_MAX;

        while(l<=r){
            int m=l+(r-l)/2;

            if(nums[l]<nums[r]){
                ans=min(ans,nums[l]);
                break;
            }
            
            ans=min(ans,nums[m]);

             if(nums[m]>nums[r]){
                l=m+1;
            }

            else{
                r=m-1;
            }

        }

        return ans;
    }
};