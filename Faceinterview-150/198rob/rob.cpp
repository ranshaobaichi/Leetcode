#include <vector>
using namespace std;

class Solution {
    public:
        int rob(vector<int>& nums) {
            // dp[0][k] -> not rob 'k'th room's maxium
            // dp[1][k] -> rob 'k'th room's maxium
            vector<vector<int>> dp(2, vector<int>(nums.size(), 0));
            dp[1][0] = nums[0];
            int n = nums.size();
            for (int i = 1; i < n; i++)
            {
                dp[0][i] = max(dp[0][i - 1], dp[1][i - 1]);
                dp[1][i] = dp[0][i - 1] + nums[i];
            }
            return max(dp[0][n - 1], dp[1][n - 1]);
        }
    };