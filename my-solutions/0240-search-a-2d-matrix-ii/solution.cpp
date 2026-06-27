class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        // Start at the Top-Right corner
        int i = 0;
        int j = col - 1;
        
        // Walk the staircase until we step off the grid
        while (i < row && j >= 0) {
            if (matrix[i][j] == target) {
                return true; 
            }
            // If target is smaller, it cannot be in this column. Move LEFT.
            else if (matrix[i][j] > target) {
                j--; 
            }
            // If target is larger, it cannot be in this row. Move DOWN.
            else {
                i++; 
            }
        }
        
        return false;
    }
};
