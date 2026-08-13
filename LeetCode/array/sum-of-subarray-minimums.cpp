class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        long long mod=1000000007;
        long long ans=0;
        stack<int> st;

        vector<int> nexts(n);
        vector<int> prevs(n);
        int i=n-1; 
        while(i>=0){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(!st.empty()){
                nexts[i]=st.top();
            }
            else{
                nexts[i]=n;
            }

            st.push(i);
            i--;
        }

        st=stack<int>();
        i=0;
        while(i<n){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(!st.empty()){
                prevs[i]=st.top();
            }
            else{
                prevs[i]=-1;
            }

            st.push(i);
            i++;
        }

        for(int i=0; i<n; i++){
            long long left_dist = i - prevs[i];
            long long right_dist = nexts[i] - i;
            
            long long total_ways = (left_dist * right_dist) % mod;
            ans = (ans + (total_ways * arr[i]) % mod) % mod;
        }

        return ans;
    }
};