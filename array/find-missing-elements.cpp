class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        vector<int> prediff(n);

        prediff[0]=0;

        for(int i=1; i<n; i++){
            prediff[i]=nums[i]-nums[i-1]-1;
        }

        vector<int> ans;
        for(int i=0; i<prediff.size(); i++){
            int num=prediff[i];
            if(num>0){
                int inc=0;
                for(int j=0; j<num; j++){
                    ans.push_back(nums[i-1]+1+inc);
                    inc++;
                }
            }
        }

        return ans;
    }
};