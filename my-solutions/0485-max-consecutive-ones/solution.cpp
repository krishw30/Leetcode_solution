#include <algorithm>
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0;
        int cmax=0;
        for(const auto &num:nums){
            if(num!=1){
                count=0;
            }
            else{
                count++;
                cmax=max(count,cmax);
            }
        }
        return cmax;
        
    }
};
