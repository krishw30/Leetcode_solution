class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> answer(n);
        int pos=0;
        int neg=1;

        for(int i=0;i<n;i++){
            if(nums[i]<0){
                answer[neg]=nums[i];
                neg=neg+2;

            }
            else{
                answer[pos]=nums[i];
                pos=pos+2;
            }

        }
        return answer;



        
    }
};
