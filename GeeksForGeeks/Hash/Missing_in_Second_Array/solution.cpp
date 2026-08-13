class Solution {
  public:
    vector<int> findMissing(vector<int>& a, vector<int>& b) {
        // code here
        int n=a.size();
        int m=b.size();
        
        unordered_map<int, int> fq;
        
        for(int i=0; i<m; i++){
            fq[b[i]]++;
        }
        
        vector<int> ans;
        
        for(int i=0; i<n; i++){
            if(!fq.count(a[i])){
                ans.push_back(a[i]);
            }
        }
        
        return ans;
    }
};

