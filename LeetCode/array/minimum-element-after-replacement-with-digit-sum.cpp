class Solution {
public:
    int minElement(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MAX;

        for(int i=0; i<n; i++){
            string st=to_string(nums[i]);
            int m=st.size();
            int sum=0;

            for(int j=0; j<m; j++){
                int t=st[j]-'0';
                sum+=t;
            }
            ans=min(sum,ans);
        }

        return ans;
    }
};