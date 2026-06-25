class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            int want=target-nums[i];
            if(m.find(want)!=m.end()){
                return{m[want],i};
            }
            
                m[nums[i]]=i;
            
        }
        return {};
    }
};
