class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (nums[mid] == target) {
                return true;
            }
            
            // Correctly handles the duplicate deadlock
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
                continue;
            }
            
            // FIX 1: Changed '<' to '<=' to correctly identify the sorted left half
            if (nums[low] <= nums[mid]) {
                // FIX 2: Changed '<=' to '<' since target == nums[mid] is already ruled out
                if (target >= nums[low] && target < nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                // Check if target lies within the sorted high half
                if (target > nums[mid] && target <= nums[high]) {
                    low = mid + 1; 
                } else {
                    high = mid - 1; 
                }
            }
        }
        // FIX 3: Return false instead of -1 because the return type is bool
        return false;
    }
};

