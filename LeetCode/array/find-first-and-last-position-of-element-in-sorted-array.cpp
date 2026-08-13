class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        int st=-1, ed=-1;

        while(l<=r){
            int m=(l+r)/2;

            if(nums[m]>=target){
                if(nums[m]==target){
                    st=m;
                }
                r=m-1;
            }
            else{
                l=m+1;
            }
        }

        if(st==-1){
            return {-1,-1};
        }

        l=st;
        r=n-1;
        while(l<=r){
            int m=(l+r)/2;

            if(nums[m]<=target){
                if(nums[m]==target){
                    ed=m;
                }
                l=m+1;
            }
            else{
                r=m-1;
            }
        }

        return {st,ed};
    }
};