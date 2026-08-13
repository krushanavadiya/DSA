class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> st;
        int k=INT_MIN;
        int i=nums.size()-1;
        while(i>=0){
            if(nums[i]<k){
                return true;
            }
            while(!st.empty() && st.top()<nums[i]){
                k=st.top();
                st.pop();
            }
            st.push(nums[i]);
            i--;
        }

        return false;
    }
};