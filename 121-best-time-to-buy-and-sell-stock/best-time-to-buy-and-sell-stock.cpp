class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = prices[0];
        int maxi = 0;
        int n = prices.size();
        for(int i=1;i<n;i++)
        {
            if(prices[i] < minprice)
            {
                minprice= prices[i];
            }
            else
            {
                int profit = prices[i] - minprice;
                maxi = max(profit,maxi);
            }
        }
        return maxi;
    }
};