class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int row=matrix.size();
        int col=matrix[0].size();
        int low=0;
        int high=(row*col)-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int row_ind=mid/col;
            int col_ind=mid%col;
            if(matrix[row_ind][col_ind]==target)return true;
            else if(target>matrix[row_ind][col_ind]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return false;
        
    }
};
