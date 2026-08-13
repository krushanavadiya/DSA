class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int l=1;
        int r=*std::max_element(nums.begin(), nums.end());
        int ans=0;

        while(l<=r){
            int mid=l+(r-l)/2;
            int sum=0;

            for(int i=0; i<n; i++){
                int div=nums[i]/mid;
                sum+=div;
                if(nums[i]%mid!=0){
                    sum+=1;
                }
            }

            if(sum<=threshold){
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