class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        
        // Changed to < to prevent the infinite loop when low == high
        while (low < high) {
            if (nums[low] < nums[high]) {
                return nums[low];
            }
            
            int mid = low + (high - low) / 2;
            
            if (nums[mid] > nums[high]) { 
                low = mid + 1;
            }
            else {
                high = mid; 
            }
        }
        return nums[low];
    }
};

