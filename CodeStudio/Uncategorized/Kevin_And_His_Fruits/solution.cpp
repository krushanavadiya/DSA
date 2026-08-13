#include <bits/stdc++.h> 
int getMaxMarker(vector<int> &arr, int N, int M)
{
    //  Write your code here.
    int n=N;
    int m=M;
    int ans=0;

    int l=1; int r=*std::max_element(arr.begin(), arr.end());

    while(l<=r){
        int mid=l+(r-l)/2;

        int fruits=0;

        for(int i=0; i<n; i++){
            if(arr[i]>mid){
                fruits+=arr[i]-mid;
            }
        }

        if(fruits>=m){ 
            ans=mid; 
            l=mid+1;
        }

        else{    
            r=mid-1;
        }
    }

    return ans;
}