class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int n=prices.size();
        for(int i=0;i<n-1;i++){
            int slope=prices[i+1]-prices[i];
            profit=profit+std::max(0,slope);
        }

        return profit;

        
    }
};
