class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        int i=1;
        stack<int> st;
        st.push(asteroids[0]);

        while(i<n){
            if(asteroids[i]<0 && !st.empty()){
                int curr=asteroids[i];
                while(!st.empty() && st.top()>0 && abs(curr)>st.top()){
                    st.pop();
                }
                if(!st.empty() && abs(curr)==st.top()){
                    st.pop();
                }
                else{
                    if(st.empty() || st.top()<0){
                        st.push(curr);
                    }
                }
            }
            else{
                st.push(asteroids[i]);
            }
            i++;
        }

        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};