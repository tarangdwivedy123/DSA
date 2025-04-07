class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int buyP = prices[0];
        for(int i=1; i<prices.size() ; i++){
            int currP = prices[i] - buyP;
            maxProfit = max(currP, maxProfit);
            buyP = min(buyP, prices[i]);
        }
        return maxProfit;
    }
};