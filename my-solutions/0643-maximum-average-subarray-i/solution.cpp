class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        int maxsum = 0;
        int n = nums.size();
        int left = 0;
        
        for(int i = 0; i < k; i++){
            sum += nums[i];
        }
        
        maxsum = sum;
        
    
        for(int right = k; right < n; right++){
            sum = sum + nums[right];  
            sum = sum - nums[left];   
            left++;
            maxsum = std::max(maxsum, sum);
        }
      
        return (double)maxsum / k; 
    }
};
