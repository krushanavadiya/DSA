class Solution {
public:
    int maxValidSplits(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        
        for(int i=-1; i<n; i++){
            vector<int> arr;
            for(int j=0; j<n; j++){
                if(j==i) continue;
                arr.push_back(nums[j]);
            }

            int m=arr.size();

            vector<int> pref(m);
            pref[0]=arr[0];
            
            for(int i=1; i<m; i++){
                pref[i]=std::gcd(pref[i-1], arr[i]);
            }

            vector<int> suff(m);
            suff[m-1]=arr[m-1];
            for(int i=m-2; i>=0; i--){
                suff[i]=std::gcd(suff[i+1],arr[i]);
            }

            int count=0;

            for(int i=0; i<m-1;i++){
                if(pref[i]==suff[i+1]) count++;
            }

            ans=max(ans, count);
        }

        return ans;
    }
};