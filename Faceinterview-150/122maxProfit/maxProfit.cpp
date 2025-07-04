/*
给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。
在每一天，你可以决定是否购买和/或出售股票。你在任何时候 最多 只能持有 一股 股票。你也可以先购买，然后在 同一天 出售。
返回 你能获得的 最大 利润 。

示例 1：
输入：prices = [7,1,5,3,6,4]
输出：7
解释：在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5 - 1 = 4。
随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6 - 3 = 3。
最大总利润为 4 + 3 = 7 。
*/
#include <vector>
using namespace std;

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            // int size = prices.size();
            // if (size <= 1) return 0;
            // vector<vector<int>> dp(prices.size(), vector<int>(prices.size(), 0));
            // // init
            // for (int i = 0; i < size; i++)
            //     for (int j = i; j < size; j++)
            //         if (prices[j] > prices[i])
            //             dp[i][j] = prices[j] - prices[i];

            // // dp_process
            // for (int len = 1; len < size; len++)
            //     for (int left = 0; left + len < size; left++)
            //         for (int k = left; k < left + len + 1; k++)
            //             dp[left][left + len] = max(dp[left][left + len], dp[left][k] + dp[k][left + len]);

            // return dp[0][size - 1];
            int ans = 0;
            for (int i = 1; i < prices.size(); i++)
                if (prices[i] > prices[i - 1])
                    ans += prices[i] - prices[i - 1];
            return ans;
        }
    };

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    Solution p;
    p.maxProfit(prices);
    return 0;
}