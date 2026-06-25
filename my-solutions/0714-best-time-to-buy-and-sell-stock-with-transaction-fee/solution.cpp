class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int cash=0;
        int hold=-prices[0];
        for(int i=0;i<prices.size();i++){
            int c=std::max(cash,hold+prices[i]-fee);
            int h=std::max(hold,cash-prices[i]);
            cash=c;
            hold=h;
        }

        return cash;

        
    }
};
