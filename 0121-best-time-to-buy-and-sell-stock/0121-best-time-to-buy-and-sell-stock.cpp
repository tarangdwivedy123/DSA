class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = INT_MAX;
        int max_p = 0;
        for(int i=0;i<prices.size();i++){
            if(min>prices[i]){
                min = prices[i];
            }
            else if(prices[i]-min > max_p){
                max_p = prices[i]-min;
            }
        }
        return max_p;
    }
};