class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        int left=0;
        int maxsum=0;
        int sum=0;
        unordered_set<int> s;
        for(int right=0;right<n;right++){
            

            while(s.find(nums[right])!=s.end()){
                s.erase(nums[left]);
                sum=sum-nums[left];
                left++;
            }
            s.insert(nums[right]);
            sum=sum+nums[right];
            maxsum=std::max(sum,maxsum);


        }
        return maxsum;
        
    }
};
