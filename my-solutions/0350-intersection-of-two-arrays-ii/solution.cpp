class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> inventory;
        vector<int> answer;
        
      
        for(int i = 0; i < nums1.size(); i++) {
            inventory[nums1[i]]++;
        }
        
        for(int i = 0; i < nums2.size(); i++) {
            if(inventory[nums2[i]] > 0) {
                answer.push_back(nums2[i]); 
                inventory[nums2[i]]--;      
            }
        }
        
        return answer;
    }
};
