#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

// class Solution {
//     public:
//         bool wordBreak(string s, vector<string>& wordDict) {
//             vector<vector<bool>> dp(s.length() + 1, vector<bool>(s.length() + 1, false));
//             for (auto &word : wordDict)
//             {
//                 size_t pos = 0;
//                 while ((pos = s.find(word, pos)) != string::npos)
//                 {
//                     dp[pos][pos + word.length()] = true;
//                     pos += 1;
//                 }
//             }
//             for (int i = 1; i <= s.length(); i++)
//                 for (int j = 0;  i + j <= s.length(); j++)
//                     for (int k = j; k < i + j; k++)
//                         if (dp[j][k] && dp[k][i + j])
//                         {
//                             dp[j][i + j] = true;
//                             break;
//                         }
//             return dp[0][s.length()];
//         }
//     };

class Solution {
    public:
        bool wordBreak(string s, vector<string>& wordDict) {
            unordered_set<string> set;
            for (auto &str : wordDict)
            {
                set.insert(str);
            }

            vector<bool> dp(s.length() + 1, false);
            dp[0] = true;
            for (int i = 0; i <= s.length(); i++)
                if (dp[i])
                    for (auto &word : wordDict)
                        if (i + word.length() <= s.length() && s.substr(0, i) + word == s.substr(0, i + word.length()))
                            dp[i + word.length()] = true;
            return dp[s.length()];
        }
    };

int main()
{
    Solution s;
    vector<string> words = {"leet", "code"};
    s.wordBreak("leetcode" ,words);
    return 0;
}