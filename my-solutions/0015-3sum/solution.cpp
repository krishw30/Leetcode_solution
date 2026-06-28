class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {   
        int n = nums.size();
        vector<vector<int>> result;
        
        std::sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n; i++) {
           
            if (nums[i] > 0) break; 
            
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            int target = -nums[i];
            int low = i + 1;  
            int high = n - 1; 
            
            while (low <  high) {
                int current_sum = nums[low] + nums[high];
                
                if (current_sum == target) {
                    result.push_back({nums[i], nums[low], nums[high]});
                    
                    low++;
                    high--;
                    
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
        return result;
    }
};

