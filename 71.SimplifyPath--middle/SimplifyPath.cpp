#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string S[300];
    int index = 0;
    string simplifyPath(string path) {
        path += '/';
        string input = "", ans = "";

        for (int i = 1; i < path.length(); i++)
            if (path[i] == '/')
                deal(input);
            else
                input += path[i];

        for (int i = 0; i < index; i++)
            ans += '/' + S[i];
        if(ans == "")
            ans += '/';
        return ans;
    }
    void deal(string &input){
        if(input == "..")
            index = index > 0 ? index - 1 : index;
        else if(!(input == "." || input == ""))
            S[index++] = input;
        input = "";
    }
};

int main()
{
    Solution pp;
    cout << pp.simplifyPath("/a//b////c/d//././/..");

    return 0;
}