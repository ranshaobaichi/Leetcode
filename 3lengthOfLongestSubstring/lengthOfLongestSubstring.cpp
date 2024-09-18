#include<iostream>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int> look_up;
        int left = 0; // 指向当前查找的字符串在原字符串中最左端下标
        int max_length = 0;
        for (int i = 0; i < s.size(); i++)
        {
            while (look_up.find(s[i]) != look_up.end())
            {
                look_up.erase(s[left]);
                left++;
            }
            look_up.insert(s[i]);
            max_length = max_length > (i - left + 1) ? max_length : (i - left + 1);
        }
        return max_length;
    }
};

int main(){
    
}