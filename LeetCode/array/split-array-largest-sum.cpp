class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0;

        for(int i=0; i<n; i++){
            sum+=nums[i];
        }

        int l=*std::max_element(nums.begin(), nums.end());
        int r=sum;
        int ans=0;

        while(l<=r){
            int mid=l+(r-l)/2;

            int split=1;
            int subSum=0;

            for(int i=0; i<n; i++){
                if(nums[i]+subSum <= mid){
                    subSum+=nums[i];
                }
                else{
                    split++;
                    subSum=nums[i];
                }
            }

            if(split<=k){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }

        return ans;
    }
};