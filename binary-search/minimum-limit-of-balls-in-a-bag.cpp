class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n=nums.size();

        long long max=*std::max_element(nums.begin(), nums.end());
        int l=1;
        long long r=max;
        long long ans=0;

        while(l<=r){
            long long mid=l+(r-l)/2;

            long long ops=0;
            for(int i=0; i<n; i++){
                int bags=nums[i]/mid;
                if(nums[i]%mid!=0){
                    bags++;
                }
                ops+=(bags-1);
            }

            if(ops<=maxOperations){
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