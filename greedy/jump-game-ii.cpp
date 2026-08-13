class Solution {
public:
    int jump(vector<int>& nums) {
        int maxjump=0;
        int current=0;
        int count=0;

        for(int i=0; i<nums.size()-1; i++){
            maxjump=max(maxjump,i+nums[i]);
            if(i==current){
                current=maxjump;
                count++;
            }
        }

        return count;

    }
};