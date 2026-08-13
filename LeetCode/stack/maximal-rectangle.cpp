class Solution {
public:
    int maxArea(vector<int>&rect , int m){
        int area=0;
        stack<int> st;

        vector<int> nexts(m);
        vector<int> prevs(m);
        int i=m-1; 
        while(i>=0){
            while(!st.empty() && rect[st.top()]>rect[i]){
                st.pop();
            }
            if(!st.empty()){
                nexts[i]=st.top();
            }
            else{
                nexts[i]=m;
            }

            st.push(i);
            i--;
        }

        st=stack<int>();
        i=0;
        while(i<m){
            while(!st.empty() && rect[st.top()]>=rect[i]){
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

        for(int i=0; i<m; i++){
           int w= nexts[i]-prevs[i]-1;
           int h= rect[i];
           area=max(area, w*h);
        }

        return area;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        //apde 0th row ma niche ni row one by one combine karshu and jya ith row ma 1 hashe ane 0th pr pn one hoi to add nkr make that 0, pachi akhi row mali jay tyare find next smaller and prev smaller and solve
        vector<int> rect(m,0);
        int ans=0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int curr=matrix[i][j];
                if(curr=='0'){
                    rect[j]=0;
                }
                else{
                    rect[j]++;
                }
            }

            ans=max(maxArea(rect, m), ans);
        }

        return ans;
    }
};