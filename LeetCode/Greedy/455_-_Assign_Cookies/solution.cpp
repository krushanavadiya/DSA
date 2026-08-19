class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=g.size();
        int m=s.size();

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ans=0;

        int i=n-1, j=m-1;

        while(i>=0 && j>=0){
            if(s[j]>=g[i]){
                ans++;
                i--;
                j--;
            }
            else{
                i--;
            }
        }

        return ans;
    }
};