int Solution::solve(vector<int> &A, int B) {
    long long n=A.size();
    int l=0;
    long long r=*std::max_element(A.begin(), A.end());
    long long ans=0;
    
    while(l<=r){
        long long mid=l+(r-l)/2;
        
        long long wood=0;
        
        for(int i=0; i<n; i++){
            if(A[i]>mid){
                wood+=(long long)A[i]-mid;
            }
        }
        
        if(wood>=B){
            ans=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    
    return ans;
}
