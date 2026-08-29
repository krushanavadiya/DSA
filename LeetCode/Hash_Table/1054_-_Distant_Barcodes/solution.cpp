class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int n=barcodes.size();
        unordered_map<int, int> fq;
        for(int i=0; i<n; i++){
            fq[barcodes[i]]++;
        }
        int count=0, val=-1;

        for(auto it: fq){
            if(it.second>count){
                count=it.second;
                val=it.first;
            }
        }

        vector<int> ans(n);
        int i=0;
        while(fq[val]>0){
            ans[i]=val;
            i+=2;
            fq[val]--;
        }

        for(auto it: fq){
            while(it.second>0){
                if(i>=n){
                    i=1;
                }
                ans[i]=it.first;
                i+=2;
                it.second--;
            }
        }

        return ans;
    }
};