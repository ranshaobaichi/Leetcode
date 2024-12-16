#include<iostream>
#include<string>
#include<vector>
using namespace std;

//BUG:TOO HARD!!!!!!!!!!!!!
/*
给你一个字符串s和一个字符规律p，请你来实现一个支持'.'和'*'的正则表达式匹配。

'.'匹配任意单个字符
'*'匹配零个或多个前面的那一个元素
所谓匹配，是要涵盖整个字符串s的，而不是部分字符串。
*/

class Solution {
public:
    bool isMatch(string s, string p);
};

bool Solution::isMatch(string s, string p)
{
    //建立状态数组，数组下标代表参加比较的字符串长度
    int m = s.size(), n = p.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, false));

    //两空字符串一定匹配
    dp[0][0] = true;

    //匹配函数
    auto matches = [=](int i, int j) -> bool
    {
        if(i==0)
            return false;
        if (p[j - 1] == '.' || s[i - 1] == p[j - 1])
            return true;
        return false;
    };

    for (int i = 0; i < m + 1; i ++)
        for (int j = 1; j < n + 1; j++)
        {
            if (p[j - 1] == '*')
            {
                if (matches(i, j - 1))
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                    dp[i][j] = dp[i][j - 2];
            }
            else
                dp[i][j] = matches(i, j) && dp[i - 1][j - 1];
        }
    return dp[m][n];
}

int main(){
    Solution p;
    p.isMatch("aaa", "ab*a*c*a");
    return 0;
}