/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices){
        int maxProfit(vector<int> & prices){
            int maxprices = 0;
    int minprices = prices[0];
    for (int i = 1; i < prices.size(); i++)
    {
        int profit = prices[i] - minprices;

        maxprices = max(profit, maxprices);

        minprices = min(prices[i], minprices);
    }

    return maxprices;
}
}
;
// @lc code=end
