class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int count=0;
        int sum=0;
        int left=0;
        float boundry=threshold*k;
        for(int i=0;i<k;i++){
            sum+=arr[i];
        }
        if(sum>=boundry)count++;
        for(int right=k;right<arr.size();right++){
            sum=sum+arr[right];
            sum=sum-arr[left];
            left++;
            if(sum>=boundry)count++;
        }
        return count;
        

        
    }
};
