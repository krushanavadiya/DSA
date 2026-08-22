class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n=arr.size();
        unordered_map<int, int> fq;

        for(int i=0; i<n; i++){
            fq[arr[i]]++;
        }

        int dup=-1, missing=-1;

        for(int i=1; i<=n; i++){
            if(fq[i]==2) dup=i;
            else if(fq[i]==0) missing=i;
        }

        return {dup, missing};
    }
};
