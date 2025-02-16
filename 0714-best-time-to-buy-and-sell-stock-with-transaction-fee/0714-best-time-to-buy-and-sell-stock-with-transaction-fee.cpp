class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
     int n = prices.size();
        if (n == 0) return 0;

        int hold = -prices[0];  // Initial state: Buying the first stock
        int cash = 0;  // No stock in hand

        for (int i = 1; i < n; i++) {
            // Update cash (profit if we sell the stock)
            cash = max(cash, hold + prices[i] - fee);
            
            // Update hold (profit if we buy/continue holding stock)
            hold = max(hold, cash - prices[i]);
        }

        return cash;  
    }
};