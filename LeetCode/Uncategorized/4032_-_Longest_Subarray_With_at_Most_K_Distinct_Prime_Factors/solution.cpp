class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int, int> fq;

        int j=0; 
        int len=0;

        for(int i=0; i<n; i++){
            int curr=nums[i];

            for(int k=2; k*k<=curr; k++){
                if(curr%k==0){
                    fq[k]++;
                    while(curr%k==0){
                        curr/=k;
                    }
                }
            }

            if(curr>1){
                fq[curr]++;
            }

            while(fq.size()>k){
                int num=nums[j];

                for(int k=2; k*k<=num; k++){
                    if(num%k==0){
                        fq[k]--;
                        if(fq[k]==0) fq.erase(k);
                    }
                    while(num%k==0){
                        num/=k;
                    }
                }

                if(num>1){
                    fq[num]--;
                    if(fq[num]==0) fq.erase(num);
                }

                j++;
            }

            len=max(len, i-j+1);
        }

        return len;
    }
};