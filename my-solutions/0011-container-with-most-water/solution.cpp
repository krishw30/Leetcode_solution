class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxarea = 0;
        int left = 0;
        int right = height.size() - 1; // Start right at the very end
        
        // Use a while loop so we control exactly which pointer moves!
        while (left < right) {
            
            // 1. Calculate current area
            int width = right - left;
            int h = std::min(height[left], height[right]);
            int area = width * h; // Just the current area, not a running sum!
            
            // 2. Update max
            maxarea = std::max(maxarea, area);
            
            // 3. Move ONLY the bottleneck
            if (height[left] <= height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return maxarea;
    }
};
