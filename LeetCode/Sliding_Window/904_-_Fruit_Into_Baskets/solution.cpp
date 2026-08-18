class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();

        int j=0;
        int len=0;

        unordered_map<int, int> fq;

        for(int i=0; i<n; i++){
            fq[fruits[i]]++;

            while(fq.size()>2){
                fq[fruits[j]]--;
                if(fq[fruits[j]]==0) fq.erase(fruits[j]);
                j++;
            }

            len=max(len, i-j+1);
        }

        return len;
    }
};