class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Phase 1: The Collision
        int slow = nums[0];
        int fast = nums[0];
        
        do {
            slow = nums[slow];           // 1 step
            fast = nums[nums[fast]];     // 2 steps
        } while (slow != fast);
        
        // Phase 2: Find the Cycle Entrance
        fast = nums[0];                  // Reset fast to the start
        while (slow != fast) {
            slow = nums[slow];           // 1 step
            fast = nums[fast];           // 1 step
        }
        
        return slow; // The exact duplicate number
    }
};
