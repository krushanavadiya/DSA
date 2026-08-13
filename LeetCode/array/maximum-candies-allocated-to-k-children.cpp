class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int n=candies.size();

        long long l=1;
        long long totalCandy=0;
        long long ans=0;

        for(int i=0; i<n; i++){
            totalCandy+=candies[i];
        }

        long long r=*std::max_element(candies.begin(), candies.end());

        if(k>totalCandy) return 0;

        while(l<=r){
            long long  mid=l+(r-l)/2;

            long long children=0;

            for(int i=0; i<n; i++){
                children+=candies[i]/mid;     
            }

            if(children>=k){    
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