class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min{10001};
        int max = 0;
        int maxProfit = 0;
        for (int i = 0; i < prices.size(); ++i) {
            if (prices[i] < min){
                min = prices[i];
                max = 0;
            }
            else {
                if (prices[i] > max) {
                    max = prices[i];
                    if(max - min > maxProfit) {
                        maxProfit = max - min;
                    }
                }
            }
        }


        return maxProfit;
    }
};