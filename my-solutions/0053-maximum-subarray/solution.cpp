class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        // PATCH 1: The All-Negative Shield
        // If the whole array is negative, your trimmers will crash. 
        // Let's just find the biggest number. If it's <= 0, return it immediately.
        int max_val = nums[0];
        for(int x : nums) {
            max_val = max(max_val, x);
        }
        if (max_val <= 0) {
            return max_val;
        }

        // YOUR EXACT LOGIC: Trimming the edges
        int start = 0;
        int end = n - 1;
        
        while(start < n){
            if(nums[start] <= 0){
                start++;
            }
            else break;
        }
        
        while(end >= 0){
            if(nums[end] <= 0) end--;
            else break;
        }

        if(start == end) return nums[start];

        int presum = 0;
        int max_sum = 0; // PATCH 2: The Camera

        // (I also fixed a tiny syntax typo here: you had a ';' after the i++)
        for(int i = start; i <= end; i++){
            // YOUR EXACT BANKRUPTCY LOGIC
            if(nums[i] < -presum){
                presum = 0;
            }
            else{
                presum += nums[i];
            }

            // Take a snapshot of the peak so we don't forget it!
            if(presum > max_sum) {
                max_sum = presum;
            }
        }
        
        // Return the snapshot, not the running total
        return max_sum;
    }
};
