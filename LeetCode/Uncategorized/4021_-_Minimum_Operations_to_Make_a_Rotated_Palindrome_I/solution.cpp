class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        int ans=INT_MAX;

        for(int i=0; i<n; i++){
            int curr=i;

            for(int j=0; j<n/2; j++){
                char c=s[(i+j)%n];
                char c2=s[(i+n-1-j)%n];

                int diff=abs(c-c2);
                curr+=min(diff, 26-diff);
            }

            ans=min(ans, curr);
        }

        return ans;
    }
};