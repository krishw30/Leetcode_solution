class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        std::stable_partition(nums.begin(), nums.end(), [](int x) {
        return x != 0; 
    });
        
    }
};
