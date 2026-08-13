class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxProduct=0;
        if(n==1){
            return nums[0];
        }
        for(int i=0; i<n; i++){
            int ans=1;
            for(int j=i; j<n; j++){
                ans*=nums[j];
                maxProduct=max(ans,maxProduct);
            }
        }

        return maxProduct;
    }
};