class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        
        vector<int> pref(n);
        pref[0]=arr[0];
        
        for(int i=1; i<n; i++){
            pref[i]=pref[i-1]+arr[i];
        }
        
        int ans=0;
        unordered_map<int, int> fq;
        
        for(int i=0; i<n; i++){
            if(pref[i]==k) ans++;
            int rem=pref[i]-k;
            if(fq.find(rem)!=fq.end()){
                ans+=fq[rem];
            }
            fq[pref[i]]++;
        }
        
        return ans;
    }
};
