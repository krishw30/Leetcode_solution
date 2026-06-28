class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> result;
        
        // 1. Sort to enable pointers and duplicate skipping
        std::sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n; i++) {
            // Skip duplicates for 'i'
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for(int j = i + 1; j < n; j++) {
                // Skip duplicates for 'j'
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int low = j + 1;
                int high = n - 1;
                
                while(low < high) {
                    // Use long long to prevent 32-bit integer overflow
                    long long current_sum = (long long)nums[i] + nums[j] + nums[low] + nums[high];
                    
                    if (current_sum == target) {
                        result.push_back({nums[i], nums[j], nums[low], nums[high]});
                        
                        low++;
                        high--;
                        
                        // Skip duplicates for 'low' and 'high'
                        while (low < high && nums[low] == nums[low - 1]) low++;
                        while (low < high && nums[high] == nums[high + 1]) high--;
                    } 
                    else if (current_sum > target) {
                        high--; 
                    } 
                    else {
                        low++;  
                    }
                }
            }
        }
        
        return result;
    }
};
