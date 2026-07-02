void merge(vector<int>& nums, int left, int mid, int right, int& count) {
    int j = mid + 1;
    for (int i = left; i <= mid; i++) {
        while (j <= right && nums[i] > 2LL *nums[j]) {
            j++;
        }
        count += j - (mid + 1);
    }
    vector<int> temp;
    int x = left;
    int y = mid + 1;
    while (x <= mid && y <= right) {
        if (nums[x] <= nums[y]) {
            temp.push_back(nums[x]);
            x++;
        } else {
            temp.push_back(nums[y]);
            y++;
        }
    }
    while (x <= mid) {
        temp.push_back(nums[x]);
        x++;
    }
    while (y <= right) {
        temp.push_back(nums[y]);
        y++;
    }

    for(int index=0;index<temp.size();index++){
        nums[index+left]=temp[index];
    }
}

void mergesort(vector<int> &nums,int left,int right,int &count){
    if(left>=right){
        return ;
    }
    int mid=left+(right-left)/2;
    mergesort(nums,left,mid,count);
    mergesort(nums,mid+1,right,count);
    merge(nums,left,mid,right,count);

}
class Solution {

public:
    int reversePairs(vector<int>& nums) {
        int left=0;
        int right=nums.size()-1;
        int count=0;
        mergesort(nums,left,right,count);
        return count;
    }
};
