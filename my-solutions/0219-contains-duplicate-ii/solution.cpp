class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
       
        int n=nums.size();
        unordered_map<int,int>index;

        for(int i=0;i<n;i++){
            if(index.find(nums[i])!=index.end()){
                if(i-index[nums[i]]<=k){
                    return true;
                }
            }
            index[nums[i]]=i;
        }
        return false;
        

        
        
    }
};
