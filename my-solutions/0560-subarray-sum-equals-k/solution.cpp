class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        std::unordered_map<int,int> check;
        check[0]=1;
        int csum=0;
        int answer=0;

        for(const auto&num:nums){
            csum=csum+num;
            if(check.find(csum-k)!=check.end()){
                answer=answer+check[csum-k];
            }
            check[csum]++;
        }

        return answer;


        
    }
};
