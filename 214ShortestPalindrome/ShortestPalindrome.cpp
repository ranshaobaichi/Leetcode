#include<iostream>
using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        auto IsPalindrome = [=](int length) -> bool
        {
            int middle = length / 2;
            int left = middle - 1,
                right = length % 2 == 0 ? middle : middle + 1;
            while (left >= 0 && right > left)
                if(s[left--]==s[right++])
                    continue;
                else
                    return false;
            return true;
        };

        auto m_reverse = [](string s) -> string
        {
            string temp;
            for (int i = 0; i < s.length(); i++)
                temp += s[s.length() - i - 1];
            return temp;
        };

        int str = 0;
        while (str < s.length())
        {    
            if (IsPalindrome(s.length() - str))
                break;
            str++;
        }
        string add = m_reverse(s.substr(s.length() - str, str));
        return add + s;
    }
};

int main(){
    Solution pp;
    cout << pp.shortestPalindrome("abcd");
    return 0;
}