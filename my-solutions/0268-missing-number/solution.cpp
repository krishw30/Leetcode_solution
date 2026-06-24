#include <cmath> 
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        long long sum=0;
        // int answer;
        long long total=n*(n+1)/2;
        for(int i=0;i<n;i++){
            sum=sum+nums[i];
        }
        return total-sum;

        
    }
};
