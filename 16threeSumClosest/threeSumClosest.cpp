/*
给你一个长度为 n 的整数数组 nums 和 一个目标值 target。
请你从 nums 中选出三个整数，使它们的和与 target 最接近。
返回这三个数的和。
假定每组输入只存在恰好一个解。
*/
/*
示例 1：
输入：nums = [-1,2,1,-4], target = 1
输出：2
解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2)。

示例 2：
输入：nums = [0,0,0], target = 1
输出：0
解释：与 target 最接近的和是 0（0 + 0 + 0 = 0）。
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdint.h>
#include <assert.h>
using namespace std;

class Solution {
    public:
        int threeSumClosest(std::vector<int> nums, int target);
};

int Solution::threeSumClosest(vector<int> nums, int target)
{
    sort(nums.begin(), nums.end());
    int length = nums.size();
    int i = 0, k, j;
    int ans = nums[0] + nums[1] + nums[2];
    while (i < nums.size() - 2)
    {
        k = i + 1;
        j = length - 1;
        while (k < j)
        {
            int sum = nums[i] + nums[k] + nums[j];
            if(sum > target) break;
            if(sum == target){
                ans = sum;
                break;
            }
            if (abs(target - sum) < abs(target - ans))
                ans = sum;
            if(sum <= target)
                k++;
            else
                j--;
        }
        i++;
        if (ans == target)
            break;
    }
    return ans;
}

int main(){
    Solution p;
    assert(p.threeSumClosest({4,0,5,-5,3,3,0,-4,-5}, -2) == 2);
    // assert(p.threeSumClosest({0, 0, 0}, 1) == 0);
    cout << "all pass!\n";
    return 0;
}