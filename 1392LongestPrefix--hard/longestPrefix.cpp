#include<string>
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    string longestPrefix(string s) {
        vector<int> next;
        next.push_back(0);
        int j = 0, max = 0, i = 1;
        while (i < s.length())
            if (s[i] == s[j]){
                i++;
                j++;
                next.push_back(j);
                max = max > j ? max : j;
            }
            else if (j == 0){
                next.push_back(0);
                i++;
            }
            else
                j = next[j - 1];
        return s.substr(0, next[s.length() - 1]);
    }
};

int main(){
    Solution p;
    cout << p.longestPrefix("babbb");
    return 0;
}