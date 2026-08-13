class Solution {
  public:
    int findPages(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        
        long long  l=*std::max_element(arr.begin(), arr.end());
        
        long long r=0;
        for(int i=0; i<n; i++){
            r+=arr[i];
        }
        
        if(n<k) return -1;
        long long ans=0;
        
        while(l<=r){
            long long mid=l+(r-l)/2;
            
            int reader=1;
            long long pages=0;
            
            for(int i=0; i<n; i++){
                if(pages+arr[i]<=mid){
                    pages+=arr[i];
                }
                else{
                    reader++;
                    pages=arr[i];
                }
            }
            
            if(reader<=k){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        
        return ans;
    }
};