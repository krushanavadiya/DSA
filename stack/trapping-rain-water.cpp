class Solution {
public:
    int trap(vector<int>& height) {
        int start=0;
        int end=height.size()-1;
        int startmax=0;
        int endmax=0;
        int res=0;
        while(start<=end){
            if(height[start]<=height[end]){
                if(height[start]>=startmax){
                    startmax=height[start];
                }
                else{
                    res+=startmax-height[start];
                }
                start++;
            }

            else{
                if(height[end]>=endmax){
                    endmax=height[end];
                }
                else{
                    res+=endmax-height[end];
                }
                end--;
            }
        }
        return res;
    }

    
};