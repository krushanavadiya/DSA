class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        int n=ranks.size();

        int carMax=(cars/n)+1;
        long long ans=0;
        long long l=1;
        int maxRank=*std::max_element(ranks.begin(), ranks.end());
        long long r=(long long)carMax*carMax*maxRank;

        while(l<=r){
            long long mid=l+(r-l)/2;
            long long totalCars=0;
            long long carRepairedByMech=0;

            for(int i=0; i<n; i++){
                carRepairedByMech=floor(sqrt(mid/ranks[i]));
                totalCars+=carRepairedByMech;
            }

            if(totalCars>=cars){
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