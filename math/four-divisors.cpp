class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int total = 0;
    
    for(int i=0;i<nums.size();i++) {
        int sum = 0;
        int count = 0;
        
        for(int j=1; j*j<=nums[i]; j++) {
            if(nums[i] % j == 0) {
                if (j * j == nums[i]) {
                    count++;
                    sum += j;
                } else {
                    count += 2;
                    sum += j;
                    sum += nums[i] / j;
                }
            }
            if(count > 4) break; 
        }
        
        if(count == 4) {
            total += sum;
        }
    }
    return total;
    }

};