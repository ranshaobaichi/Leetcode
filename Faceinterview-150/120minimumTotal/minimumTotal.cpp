#include <vector>
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int sz = triangle.size();
        if (sz == 1)
            return triangle[0][0];
        vector<int> dp(triangle.back());
        for (int i = sz - 2; i >= 0; i--)
            for (int j = 0; j <= i; j++)
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);

        return dp[0];
    }
};