class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> c(3);
        int n=stones.size();

        for(int i=0; i<n; i++){
            c[stones[i]%3]++;

        }

        if(c[0]%2==0) return c[1]>0 && c[2]>0;

        return abs(c[1]-c[2])>2;
    }
};