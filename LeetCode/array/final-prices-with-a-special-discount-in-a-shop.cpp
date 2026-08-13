class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n=prices.size();
        vector<int> ans(n);
        stack<int> st;
        int i=n-1;
        while(i>=0){
            while(!st.empty() && st.top()>prices[i]){
                st.pop();
            }
            if(!st.empty() && st.top()<=prices[i]){
                int curr=prices[i];
                int top=st.top();
                // st.pop();
                int dis=curr-top;
                ans[i]=dis;
            }
            else{
                ans[i]=prices[i];
            }
            
            st.push(prices[i]);
            i--;
        }

        return ans;
    }
};