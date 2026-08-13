class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        int n=position.size();

        sort(position.begin(), position.end());

        int r=position[n-1]-position[0];
        int l=0;
        int ans=0;

        while(l<=r){
            int mid=l+(r-l)/2;
            int balls=1;
            int curr=position[0];

            for(int i=1; i<n; i++){
                int force=abs(curr-position[i]);

                if(force>=mid){
                    curr=position[i];
                    balls++;
                }
            }

            if(balls>=m){
                ans=mid;
                l=mid+1;
            }

            else{
                r=mid-1;
            }
        }

        return ans;

    }
};