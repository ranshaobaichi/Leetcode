#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<map>
using namespace std;

map<int, string> num{
    {2, "abc"},
    {3, "def"},
    {4, "ghi"},
    {5, "jkl"},
    {6, "mno"},
    {7, "pqrs"},
    {8, "tuv"},
    {9, "wxyz"},
};

// class Solution {
// public:
//     vector<string> letterCombinations(string digits) {
//         if (digits.length() == 0)
//             return vector<string>();
//         in("", digits[0] - '0');
//         digits.erase(digits.begin());
//         while (!digits.empty())
//         {
//             int n = digits[0] - '0';
//             digits.erase(digits.begin());
//             in(ans[0], n);
//             in(ans[1], n);
//             in(ans[2], n);
//             if (_7_9)
//                 in(ans[3], n);
//             ans.erase(ans.begin(), ans.begin() + 3 + _7_9);
//             if (n != 7 || n != 9)
//                 _7_9 = false;
//         }
//         return ans;
//     }
//     void in(string add,int n)
//     {
//         ans.push_back(add + num.find(n)->second[0]);
//         ans.push_back(add + num.find(n)->second[1]);
//         ans.push_back(add + num.find(n)->second[2]);
//         if (n == 7 || n == 9)
//         {
//             ans.push_back(add + num.find(n)->second[3]);
//             _7_9 = true;
//         }
//     }
//     vector<string> ans;
//     bool _7_9 = false;
// };

class Solution{
public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
            return vector<string>();
        queue<string> ans;
        ans.push("");
        int length = 1;
        while (!digits.empty())
        {
            int n = digits[0] - '0';
            digits.erase(digits.begin());
            int l = num.find(n)->second.length();
            string s = num.find(n)->second;
            while (length > 0)
            {
                for (int i = 0; i < l; i++)
                    ans.push(ans.front() + s[i]);
                ans.pop();
                length--;
            }
            length = ans.size();
        }
        vector<string> a;
        while (!ans.empty())
        {
            a.push_back(ans.front());
            ans.pop();
        }
        return a;
    }
};

int main(){
    Solution pp;
    vector<string> ans = pp.letterCombinations("7");
    for (vector<string>::iterator i = ans.begin(); i != ans.end(); i++)
        cout << *i << ' ';
    return 0;
}