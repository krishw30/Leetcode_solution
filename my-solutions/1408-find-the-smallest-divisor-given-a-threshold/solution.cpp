class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int low=1;
        int answer;
        int high=*std::max_element(nums.begin(),nums.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            int sum=0;
            for(int i=0;i<n;i++){
                int k=nums[i];
                sum=sum+(mid+k-1)/mid;
            }
            if(sum<=threshold){
                high=mid-1;
                answer=mid;
            }
            else{
                low=mid+1;
            }
            

        }
        return answer;
        
    }
};
