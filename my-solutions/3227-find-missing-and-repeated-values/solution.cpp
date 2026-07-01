class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        int size=n*n;
        vector<int> count(size+1,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                count[grid[i][j]]++;
            }
        }
        int miss=-1;
        int rep=-1;

        for(int i=0;i<=size;i++){
            if(count[i]==2)
            {
                rep=i;
            }
            else if(count[i]==0){
                miss=i;
            }
        }
        return{rep,miss};

        
    }
};
