class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       auto it = std::unique(nums.begin(), nums.end());
        
        // Optional: Erase the trailing duplicate elements
        nums.erase(it, nums.end()); 
        
        return nums.size();
        
    }
};
