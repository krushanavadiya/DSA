class Solution {
  public:
    int minTime(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        int l=*std::max_element(arr.begin(), arr.end());
        int total=0;
        for(int i=0; i<n; i++){
            total+=arr[i];
        }
        int r=total;
        int ans=0;
        
        while(l<=r){
            int mid=l+(r-l)/2;
            
            int painter=1;
            int totalTime=0;
            
            for(int i=0; i<n; i++){
                if(arr[i]+totalTime<=mid){
                    totalTime+=arr[i];
                }
                else{
                    painter++;
                    totalTime=arr[i];
                }
            }
            
            if(painter<=k){
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