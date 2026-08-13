class Solution {
public:
    int maxWidthRamp(vector<int>& a) {
        
        stack<pair<int,int>> st;
        int n = a.size();

        for(int i = 0; i<n ; i++){
            if(st.empty() || st.top().first > a[i]){
                st.push({a[i],i});
            }
        }
        int ans = 0;
        for(int i = n-1; i>=0 ; i--){
            while(st.empty() == false && a[i] >= st.top().first){
                ans = max(ans , i-st.top().second);
                st.pop();
            }
        }

        return ans;

    }
};
