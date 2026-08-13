class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int> leftsum(n,0);
        vector<int> rightsum(n,0);
        vector<int> ans;

        for(int i=0; i<n; i++){
            if(i>0){
                int ls=0;
                for(int j=0; j<i; j++){
                    ls+=nums[j];
                }
                leftsum[i]=ls;
            }
            if(i<n-1){
                int rs=0;
                for(int j=i+1; j<n; j++){
                    rs+=nums[j];
                }
                rightsum[i]=rs;
            }
            
            ans.push_back(abs(leftsum[i] - rightsum[i]));
        }

        return ans;

    }
};