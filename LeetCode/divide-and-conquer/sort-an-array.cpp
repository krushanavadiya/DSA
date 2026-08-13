class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }

    void mergeSort(vector<int>& nums, int l, int r){
        if(l>=r) return;

        int mid=l+(r-l)/2;

        mergeSort(nums, l, mid);
        mergeSort(nums, mid+1, r);

        merge(nums, l, mid, r);
    }

    void merge(vector<int>& nums, int l, int mid, int r){
        int n1 = mid - l + 1;
        int n2 = r - mid;

        // Create temporary vectors to hold the split data
        std::vector<int> L(n1), R(n2);

        // Copy data to temporary vectors
        for (int i = 0; i < n1; i++) L[i] = nums[l + i];
        for (int j = 0; j < n2; j++) R[j] = nums[mid + 1 + j];

        // Merge the temporary vectors back into the original numsay
        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) nums[k++] = L[i++]; // '<=' ensures stability
            else nums[k++] = R[j++];
        }

        // Copy remaining elements
        while (i < n1) nums[k++] = L[i++];
        while (j < n2) nums[k++] = R[j++]; 
    }
};