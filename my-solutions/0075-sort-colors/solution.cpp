#include <algorithm>
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // std::sort(nums.begin(),nums.end());
        int count0{}, count1{}, count2{};
        int n=nums.size();
        for(const auto &num:nums){
            if(num==0) count0++;
            else if(num==1)count1++;
            else count2++;
        }
        for(int i=0;i<n;i++){
            if(count0){
                nums[i]=0;
                count0--;
                continue;
                }
            else if(count1){
                nums[i]=1;
                count1--;
                continue;
                
            }
            else{
                nums[i]=2;
                count2--;
                continue;
            }
        
        }
        
    }
};
