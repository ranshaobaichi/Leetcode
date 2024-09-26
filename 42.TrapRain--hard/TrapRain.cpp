#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

//FIXME:时间复杂度优化

class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0;
        unordered_map<int,int> T;
        for (int i = 0; i < height.size(); i++)
            for (int k = 1; k <= height[i]; k++)
            {
                if (T.find(k) != T.end())
                    sum += i - T[k] - 1;
                T[k] = i;
            }
        return sum;
    }
};

int main(){
    vector<int> a = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    Solution pp;
    cout << pp.trap(a);
    return 0;
}