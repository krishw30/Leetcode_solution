#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        // 1. Setup: Add the Ground Zero building
        restrictions.push_back({1, 0});
        
        // 2. Sort by building ID so we process left-to-right physically
        sort(restrictions.begin(), restrictions.end());
        
        int m = restrictions.size();
        
        // 3. Pass 1: The Left-to-Right Shockwave
        for (int i = 1; i < m; i++) {
            int distance = restrictions[i][0] - restrictions[i-1][0];
            int limitFromLeft = restrictions[i-1][1] + distance;
            
            // Force the current restriction down if the left neighbor pulls it
            restrictions[i][1] = min(restrictions[i][1], limitFromLeft);
        }
        
        // 4. Pass 2: The Right-to-Left Shockwave
        for (int i = m - 2; i >= 0; i--) {
            int distance = restrictions[i+1][0] - restrictions[i][0];
            int limitFromRight = restrictions[i+1][1] + distance;
            
            // Force the current restriction down if the right neighbor pulls it
            restrictions[i][1] = min(restrictions[i][1], limitFromRight);
        }
        
        // 5. Find the highest peak mathematically possible between any two restrictions
        int max_height = 0;
        for (int i = 1; i < m; i++) {
            int h1 = restrictions[i-1][1];
            int h2 = restrictions[i][1];
            int distance = restrictions[i][0] - restrictions[i-1][0];
            
            // The mathematical formula for two slopes intersecting
            int peak = max(h1, h2) + (distance - abs(h1 - h2)) / 2;
            max_height = max(max_height, peak);
        }
        
        // 6. Don't forget the unrestrained empty space at the very end of the city!
        int last_id = restrictions.back()[0];
        int last_h = restrictions.back()[1];
        max_height = max(max_height, last_h + (n - last_id));
        
        return max_height;
    }
};
