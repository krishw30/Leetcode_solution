class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int low=*std::max_element(weights.begin(),weights.end());
        int high=n*low;
        while(low<=high){
            int mid=low+(high-low)/2;
            int cap=mid;
            long long day=1;
            for(int i=0;i<n;i++){
                if(cap-weights[i]>=0){
                    cap=cap-weights[i];

                }
                else{
                    day++;
                    cap=mid;
                    cap=cap-weights[i];
                }
            }
            if(day<=days){
                high=mid-1;

            }
            else{
                low=mid+1;

            }
        }
        return low;
        
    }
};
