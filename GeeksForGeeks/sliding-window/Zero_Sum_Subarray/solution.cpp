class Solution {
  public:
    bool subArrayExists(vector<int>& arr) {
        // code here
        int n=arr.size();
        
        vector<int> pref(n);
        pref[0]=arr[0];
        
        for(int i=1; i<n; i++){
            pref[i]=arr[i]+pref[i-1];
        }
        
        unordered_map<int, int> fq;
        
        for(int i=0; i<n; i++){
            if(pref[i]==0) return true;
            
            if(fq.find(pref[i])!=fq.end()){
                return true;
            }
            
            fq[pref[i]]++;
        }
        
        return false;
    }
};
