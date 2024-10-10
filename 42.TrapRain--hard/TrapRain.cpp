#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0, i = 0;
        stack<int> S;
        while (height[i] == 0 && i != height.size() - 1)
            i++;
        S.push(i++);
        while (i < height.size())
            if (height[i] > height[S.top()] && S.size() >= 2)
            {
                int top = S.top();
                S.pop();
                int left = S.top();
                sum += (min(height[i], height[left]) - height[top]) * (i - left - 1);
            }
            else
            {
                if (height[i] > height[S.top()])
                    S.pop();
                S.push(i);
                i++;
            }
        return sum;
    }
};

int main(){
    vector<int> a = {4,2,0,3,2,5};
    Solution pp;
    cout << pp.trap(a);
    return 0;
}