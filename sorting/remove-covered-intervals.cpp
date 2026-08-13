class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1]; // If start times tie, sort by end time DESCENDING
            }
            return a[0] < b[0];     // Otherwise, sort by start time ASCENDING
        });
        
        vector<vector<int>> ans;
        for(int i=0; i<n-1; i++){
            if(intervals[i][0]<=intervals[i+1][0] && intervals[i][1]>=intervals[i+1][1]){
                intervals[i+1][0]=intervals[i][0];
                intervals[i+1][1]=max(intervals[i][1], intervals[i+1][1]);
            }
            else{
                ans.push_back({intervals[i][0], intervals[i][1]});
            }
        }
 
        ans.push_back({intervals[n-1][0], intervals[n-1][1]});
        
        return ans.size();
    }
};