class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        
        // The Boundaries
        int low = *std::max_element(nums.begin(), nums.end());
        long long high = 0;
        for (int i = 0; i < n; i++) {
            high += nums[i];
        }
        
        // The Engine
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            
            long long cap = mid;
            long long sum = 0;
            int count = 1;
            
            for (int i = 0; i < n; i++) {
                if (sum + nums[i] <= cap) {
                    sum = sum + nums[i];
                } else {
                    count++;
                    sum = nums[i];
                }
            }
            
            // The Homing Missile
            if (count <= k) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return low;
    }
};
