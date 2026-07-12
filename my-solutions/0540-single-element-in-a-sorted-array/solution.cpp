class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        
        // 1. The Boundary Guards (Protects against out-of-bounds)
        if (n == 1) return nums[0];
        if (nums[0] != nums[1]) return nums[0];
        if (nums[n - 1] != nums[n - 2]) return nums[n - 1];
        
        // 2. The Search Space (Locked inward to prevent segmentation faults)
        int low = 1;
        int high = n - 2;
        
        // 3. The Engine
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // Rule 1: The Target
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
                return nums[mid];
            }
            
            // Rule 2: The Left Side (Even/Odd pairs)
            if ((mid % 2 == 1 && nums[mid] == nums[mid - 1]) || 
                (mid % 2 == 0 && nums[mid] == nums[mid + 1])) {
                low = mid + 1; // Jump Right
            } 
            // Rule 3: The Right Side (Odd/Even pairs)
            else {
                high = mid - 1; // Jump Left
            }
        }
        
        return -1;
    }
};
