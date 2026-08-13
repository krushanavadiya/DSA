class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxwater=0;
        int start=0;
        int end=height.size()-1;
        while(start<=end){
            if (height[start]<height[end])
                {
                maxwater=max((end-start)*height[start],maxwater);
                start+=1;
                }
            else{
                maxwater=max((end-start)*height[end],maxwater);
                end-=1;
            }
        }
        return maxwater;
        
    }
};