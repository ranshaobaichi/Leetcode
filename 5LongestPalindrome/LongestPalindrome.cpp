#include<iostream>
#include<string>
using namespace std;

/*给你一个字符串 s，找到 s 中最长的回文子串。*/

class Solution {
public:
    string longestPalindrome(string s) {
        //lamda表达式 后续在该函数内可调用
        //返回从给定范围向外扩展确定最长子串
        auto IsPalindrome = [=](int left, int right) -> string
        {
            int len = 0;
            while (left >= 0 && right < s.length() && s[left] == s[right])
            {
                len += 2;
                left--;
                right++;
            }
            if (len > 0)
                return s.substr(left + 1, right - left - 1);
            else
                return "";
        };

        string max = "";

        for (int i = 0; i < s.length(); i++)
        {
            string a = IsPalindrome(i, i);
            string b = IsPalindrome(i, i + 1);
            if (a.length() > max.length()) max = a;
            if (b.length() > max.length()) max = b;
        }

        return max;
    }
};

int main(){
    string s = "cbbd";
    Solution pp;
    cout << pp.longestPalindrome(s);

    return 0;
}