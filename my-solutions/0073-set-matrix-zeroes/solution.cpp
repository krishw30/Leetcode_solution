class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        int col0 = 1; // Our single external tracker for the first column
        
        // PHASE 1: Scan and Project to Edges
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    // Mark the row ledger
                    matrix[i][0] = 0;
                    
                    // Mark the column ledger
                    if (j != 0) {
                        matrix[0][j] = 0;
                    } else {
                        col0 = 0; // Special case for the first column
                    }
                }
            }
        }
        
        // PHASE 2: Detonate the Core (Start from 1, leave ledgers alone)
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        // PHASE 3: Detonate the Edges (Row 0 first, then Col 0)
        if (matrix[0][0] == 0) {
            for (int j = 0; j < cols; j++) {
                matrix[0][j] = 0;
            }
        }
        
        if (col0 == 0) {
            for (int i = 0; i < rows; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
