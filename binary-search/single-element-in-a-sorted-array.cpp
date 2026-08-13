class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();

        int l=1, r=n-2;

        int ans=-1;
        if(n==1) return nums[0];
        if (nums[0] != nums[1]) return nums[0];
        if (nums[n - 1] != nums[n - 2]) return nums[n - 1];

        while(l<r){
            int m=l+(r-l)/2;

            if(nums[m]!=nums[m-1] && nums[m]!=nums[m+1]){
                ans=nums[m];
                break;
            }

            if(m%2==0 ){
                if( nums[m]!=nums[m+1]){
                    r=m;
                }
                
                else if(nums[m]!=nums[m-1]){
                    l=m;
                }
            }

            else {
                if(nums[m]!=nums[m-1]){
                    r=m;
                }
                else if(nums[m]!=nums[m+1]){
                    l=m;
                }
            }
        }

        return ans;
    }
};