class Solution {
  public:
    bool findPair(vector<int> &arr, int x) {
        // code here
        int n=arr.size();
        unordered_map<int, int> fq;
        
        for(int i=0; i<n; i++){
            fq[arr[i]]++;
        }
        
        for(int i=0; i<n; i++){
            int rem=x+arr[i];
            if(x==0){
                if(fq[rem]>1) return true;
            }
            else{
                if(fq.count(rem)) return true;
            }
        }
        
        return false;
    }
};

