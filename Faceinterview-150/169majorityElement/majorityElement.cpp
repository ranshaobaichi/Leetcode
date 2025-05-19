/*
给定一个大小为 n 的数组 nums ，返回其中的多数元素。
多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。
你可以假设数组是非空的，并且给定的数组总是存在多数元素。

示例 1：
输入：nums = [3,2,3]
输出：3

示例 2：
输入：nums = [2,2,1,1,1,2,2]
输出：2
*/

#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
    public:
    /*
    “同归于尽消杀法” ：
    由于多数超过50%, 比如100个数，那么多数至少51个，剩下少数是49个。
    第一个到来的士兵，直接插上自己阵营的旗帜占领这块高地，此时领主winner就是这个阵营的人，现存兵力count=1。
    如果新来的士兵和前一个士兵是同一阵营，则集合起来占领高地，领主不变，winner 依然是当前这个士兵所属阵营，
    现存兵力 count++；

    如果新来到的士兵不是同一阵营，则前方阵营派一个士兵和它同归于尽。 此时前方阵营兵力count --。
    （即使双方都死光，这块高地的旗帜 winner 依然不变，因为已经没有活着的士兵可以去换上自己的新旗帜）

    当下一个士兵到来，发现前方阵营已经没有兵力，新士兵就成了领主，winner 变成这个士兵所属阵营的旗帜，
    现存兵力 count ++。
    就这样各路军阀一直以这种以一敌一同归于尽的方式厮杀下去，直到少数阵营都死光，那么最后剩下的几个必然属于多数阵营，winner 就是多数阵营。
    （多数阵营 51个，少数阵营只有49个，死剩下的2个就是多数阵营的人）
    */
        int mmajorityElement(vector<int> nums) {
            int winner = nums[0];
            int count = 1;
            for (int i = 1; i < nums.size(); i++) {
                if (winner == nums[i]) {
                    count++;
                } else if (count == 0) {
                    winner = nums[i];
                    count++;
                } else {
                    count--;
                }
            }
            return winner;
        }
        int majorityElement(vector<int>& nums) {
            return findMajorityElement(nums, 0, nums.size());
        }
        /// @brief 递归找众数
        /// @param nums 数组
        /// @param left 左端点（包含）
        /// @param right 右端点（不包含）
        /// @return 众数
        int findMajorityElement(vector<int> &nums, int left, int right)
        {
            if (left == right || left + 1 == right)
                return nums[left];
            int mid = (left + right) / 2;
            int leftElement = findMajorityElement(nums, left, mid);
            int rightElement = findMajorityElement(nums, mid, right);
            if(leftElement == rightElement)
                return leftElement;
            else
            {
                int left_cnt = 0, right_cnt = 0;
                for (int i = left; i < right; i++)
                    if (nums[i] == leftElement)
                        left_cnt++;
                    else if (nums[i] == rightElement)
                        right_cnt++;
                return left_cnt > right_cnt ? leftElement : rightElement;
            }   
        }
    };

int main()
{
    vector<int> v= {2,2,1,1,1,2,2};
    Solution S;
    int a = S.majorityElement(v);
    return 0;
}