class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();

        if((long long)m*k>n) return -1;

        int ans=-1;

        int l=*std::min_element(bloomDay.begin(), bloomDay.end());
        int r=*std::max_element(bloomDay.begin(), bloomDay.end());

        while(l<=r){
            int mid=l+(r-l)/2;
            
            int bqMade=0;
            int flowerPicked=0;

            for(int i=0; i<n; i++){
                  
                if(bloomDay[i]<=mid){
                    flowerPicked++;
                    if(flowerPicked==k){
                        bqMade++;
                        flowerPicked=0;
                    }     
                }
                else{
                    flowerPicked=0;
                }
            }

            if(bqMade>=m){
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