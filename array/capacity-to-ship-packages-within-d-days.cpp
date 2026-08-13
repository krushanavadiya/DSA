class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int r=0;
        int l=*std::max_element(weights.begin(), weights.end());
        int ans=0;

        for(int i=0; i<n; i++){
            r+=weights[i];
        }

        while(l<=r){
            int mid=l+(r-l)/2;

            int weight=0;
            int day=1;

            for(int i=0; i<n; i++){
                if(weight+weights[i]<=mid){
                    weight+=weights[i];
                }
                else{
                    weight=weights[i];
                    day++;
                   
                }
            }

            if(day<=days){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }

        return ans;

    }
};