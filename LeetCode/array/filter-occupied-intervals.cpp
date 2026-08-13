class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        int n=occupiedIntervals.size();
        vector<int> st(n);
        vector<int> end(n);

        sort(occupiedIntervals.begin(), occupiedIntervals.end());
        
        for(int i=0; i<n; i++){
            st[i]=occupiedIntervals[i][0];
            end[i]=occupiedIntervals[i][1];
        }

        vector<vector<int>> rem;

        for(int i=0; i<n-1; i++){
            if(end[i]>=st[i+1] || end[i]+1>=st[i+1]){
                st[i+1]=st[i];
                end[i+1]=max(end[i], end[i+1]);
            }
            else{
                rem.push_back({st[i], end[i]});
            }
        }

        rem.push_back({st[n-1], end[n-1]});

        vector<vector<int>> ans;
        int m=rem.size();

        for(int i=0; i<m; i++){
            int st=rem[i][0];
            int end=rem[i][1];

            if(st>freeEnd || end<freeStart){
                ans.push_back({st,end});
            }

            else{
                if(st<freeStart){
                    ans.push_back({st, freeStart-1});
                }
                if(end>freeEnd){
                    ans.push_back({freeEnd+1,end});
                }
            }
        }

        return ans;
    }
};