class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int mid_expected=mid+1;
            int already_missed=arr[mid]-mid_expected;
            if(already_missed<k){
                low=mid+1;
            }
            else {
                high=mid-1;
            }
        
        }
        return low+k;
    }
};
