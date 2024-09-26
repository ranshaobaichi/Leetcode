#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string smallestSubsequence(string s) {
        if (s == "")
            return "";
        string *ans = new string[s.length()];
        ans[0] = s[0];
        for (int i = 1; i < s.length(); i++)
        {   
            if(ans[i-1].find(s[i]) == -1)
            {
                while (*(ans[i - 1].end() - 1) > s[i])
                    if (s.rfind(*(ans[i - 1].end() - 1)) > i)
                        ans[i - 1].pop_back();
                    else
                        break;
                ans[i] = ans[i - 1] + s[i];
            }
        }
        
        return ans[s.length() - 1];
    }
};

int main(){
    Solution pp;
    cout << pp.smallestSubsequence("cbaacabcaaccaacababa");
    return 0;
}
