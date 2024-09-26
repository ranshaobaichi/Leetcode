#include<iostream>
#include<string>
#include<map>
#include<stack>
using namespace std;

map<char, int> Parentheses{
    {'(', 0},
    {')', 0},
    {'{', 1},
    {'}', 1},
    {'[', 2},
    {']', 2}
};

class Solution {
public:
    bool isValid(string s) {
        stack<char> T;
        for (int i = 0; i < s.length(); i++)
            switch (s[i])
            {
            case '(':case '{':case '[':
                T.push(s[i]);
                break;
            case ')':case '}':case ']':
                if (!T.empty() && (Parentheses[T.top()] == Parentheses[s[i]]))
                    T.pop();
                else
                    return false;
                break;
            }
        return T.empty();
    }
};

int main(){
    Solution pp;
    cout << pp.isValid("");

}