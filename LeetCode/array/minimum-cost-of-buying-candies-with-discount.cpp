class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n=cost.size();

        sort(cost.begin(), cost.end(), greater<int>());
        int i=0;
        int ans=0;

        for(int i=0; i<n; i++){
            if((i+1)%3==0){
                continue;
            }
            else{
                ans+=cost[i];
            }
        }

        return ans;
    }
};