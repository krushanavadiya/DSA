class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> pos(n/2);
        vector<int> neg(n/2);
        int j=0;
        int k=0;
        for(int i=0; i<n; i++){
            if(nums[i]>0){
                pos[j]=nums[i];
                j++;
            }
            else{
                neg[k]=nums[i];
                k++;
            }
        }

        vector<int> ans(n);
        for(int i=0; i<n/2; i++){   
            ans[2*i]=pos[i];
            ans[(2*i)+1]=neg[i];
        }

        return ans;
    }
};