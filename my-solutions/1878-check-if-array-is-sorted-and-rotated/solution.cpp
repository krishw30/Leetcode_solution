class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            
            int j=0;
            while(j<n-1){
                int pos=(i+j)%n;
                int pos2=(i+j+1)%n;
                if(nums[pos]>nums[pos2]){
                    break;
                }

                j++;
                
            }
            if(j==(n-1)){
                return true;
            }

        }
        return false;
        
    }
};
