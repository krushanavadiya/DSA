class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n=matches.size();

        unordered_map<int, int> win;
        unordered_map<int, int> lose;

        for(int i=0; i<n; i++){
            int n1=matches[i][0];
            int n2=matches[i][1];

            win[n1]++;
            lose[n2]++;
        }

        vector<vector<int>> ans(2);

        vector<int> noLose;

        for(auto it: win){
            if(lose.find(it.first)==lose.end()){
                noLose.push_back(it.first);
            }
        }

        vector<int> oneLose;
        for(auto it: lose){
            if(it.second==1){
                oneLose.push_back(it.first);
            }
        }

        sort(noLose.begin(), noLose.end());
        ans[0]=noLose;

        sort(oneLose.begin(), oneLose.end());
        ans[1]=oneLose;

        return ans;
    }
};