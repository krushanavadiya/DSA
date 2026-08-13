class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        // int m=intervals[0].size();
        // vector<int> st(n);
        // vector<int> end(n);

        // sort(intervals.begin(), intervals.end());

        // for(int i=0; i<n; i++){
        //     st[i]=intervals[i][0];
        //     end[i]=intervals[i][1];
        // }

        // if(n<=1) return intervals;

        // vector<vector<int>> ans;

        // for(int i=0; i<n-1; i++){
        //     if(end[i]>=st[i+1]){
        //         st[i+1]=st[i];
        //         end[i+1]=max(end[i], end[i+1]);
        //     }
        //     else{
        //         vector<int> arr(m);
        //         arr[0]=st[i];
        //         arr[1]=end[i];
        //         ans.push_back(arr);
        //     }
        // }

        // vector<int> lastinterval(m);
        // lastinterval[0]=st[n-1];
        // lastinterval[1]=end[n-1];
        // ans.push_back(lastinterval);

        // return ans;

        if(n < 2) return intervals;
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i = 1; i < n; i++){
            if(ans.back()[1] >= intervals[i][0]){
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }else{
                ans.push_back(intervals[i]);
            }
        }
        return ans; 
    }

};