class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();

        stack<int> st;
        int i=(2*n)-1;
        vector<int> ans(n);
        while(i>=0){
            while(!st.empty() && st.top()<=nums[i%n]){
                st.pop();
            }
            if(!st.empty()){
                ans[i%n]=st.top();
            }
            else{
                ans[i%n]=-1;
            }
            st.push(nums[i%n]);
            i--;
        }

        return ans;
    }
};