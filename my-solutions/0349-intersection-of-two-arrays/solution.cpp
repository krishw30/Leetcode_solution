class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> check;
        vector<int> answer;
        for(int i=0;i<nums1.size();i++){
            check.insert(nums1[i]);
        }
        for(int i=0;i<nums2.size();i++){
            if(check.find(nums2[i])!=check.end()){
                answer.push_back(nums2[i]);
                check.erase(nums2[i]);
            }
        }
        return answer;
        
    }
};
