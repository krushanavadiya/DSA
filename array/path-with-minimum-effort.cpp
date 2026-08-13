class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int rows = heights.size();
        int cols = heights[0].size();
        
       priority_queue<tuple<int, int, int>, 
                       vector<tuple<int, int, int>>, 
                       greater<tuple<int, int, int>>> pq;
        
        vector<vector<int>> minEffort(rows, vector<int>(cols, INT_MAX));
        
        minEffort[0][0] = 0;
        pq.push({0, 0, 0});
        
        int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        while (!pq.empty()) {
            auto [current_effort, r, c] = pq.top();
            pq.pop();
            
            if (r == rows - 1 && c == cols - 1) {
                return current_effort;
            }
            
            if (current_effort > minEffort[r][c]) {
                continue;
            }
            
            for (auto& dir : dirs) {
                int nr = r + dir[0];
                int nc = c + dir[1];
                
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                    int edgeWeight = abs(heights[r][c] - heights[nr][nc]);
                    int newEffort = max(current_effort, edgeWeight);
                    
                    if (newEffort < minEffort[nr][nc]) {
                        minEffort[nr][nc] = newEffort;
                        pq.push({newEffort, nr, nc});
                    }
                }
            }
        }
        return 0;
    }
};