class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;
        int mid;
        int k=target;
        
        while(left<=right){

            mid=(left+right)/2;

            if(nums[mid]==k){
             return mid;}

            if(nums[left]<=nums[mid]){
                if(nums[left]<=k && nums[mid]>k){
                    right=mid-1;
                }
                else{
                    left=mid+1;
                }
            }

            else {
                if(nums[right]>=k && nums[mid]<k){
                    left=mid+1;
                }
                else{
                    right=mid-1;
                }
            }
          
        
            
        }
        return -1;
        
    }
};