class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n=arr.size();

        unordered_map<long long, long long > fq;

        for(int i=0; i<n; i++){
            long long rem=(k+(arr[i]%k))%k;
            fq[rem]++;
        }

        for(int i=0; i<k; i++){
            if(i==0 && fq[i]%2!=0) return false;
            else if(i*2==k && fq[i]%2!=0) return false;
            else if(i!=0 && i*2!=k && fq[i]!=fq[k-i]) return false;
        }

        return true;
    }
};