class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int p1=0;
        int n=nums.size();
        for(int p2=0;p2<n;p2++){
            if(nums[p2]!=0){
                nums[p1]=nums[p2];
                p1++;
            }
        }
        for(int i=p1;i<n;i++){
            nums[i]=0;
        }

        
    }
};
