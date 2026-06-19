class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        int freq=0;
        int left=0;
        long long current=0;
        for(int right=0;right<n;right++){
            current+=nums[right];
            long long target=nums[right];
            long long cost=(right-left+1)*target-current;

        while(cost>k){
            current=current-nums[left];
            left++; //slide the window
            cost=(right-left+1)*target-current;
        }

        freq=max(freq,right-left+1);
        }
        
        
        return freq;
    }
};
