class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int cmax=0;
        int count=0;
        int left=0;
    
    
        int zero=0;
        for(int right=0;right<n;right++){
            if(nums[right]==0){
                zero++;
            }
            while(zero>k){
                if(nums[left]==0){
                    zero--;
                }
                    left++;
            }
            count=right-left+1;
            cmax=std::max(cmax,count);

        }

        return cmax;
        




        
    }
};
