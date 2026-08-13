class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int ans=0;
        
        // for(int i=0; i<n; i++){
        //     int curr=heights[i];
        //     int countl=0;
        //     int j=i;
        //     while(j>=0 && curr<=heights[j]){
        //         countl++;
        //         j--;
        //     }

        //     int countr=0;
        //     int k=i;
        //     while(k<n && curr<=heights[k]){
        //         countr++;
        //         k++;
        //     }

        //     ans=max(ans, curr*(countl+countr-1));
        // }


        stack<int> st;

        vector<int> nexts(n);
        vector<int> prevs(n);
        int i=n-1; 
        while(i>=0){
            while(!st.empty() && heights[st.top()]>heights[i]){
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
            while(!st.empty() && heights[st.top()]>=heights[i]){
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
           int w= nexts[i]-prevs[i]-1;
           int h= heights[i];
           ans=max(ans, w*h);
        }
        return ans;
    }
};