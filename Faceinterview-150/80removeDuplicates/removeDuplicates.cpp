/*
给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使得出现次数超过两次的元素只出现两次 
，返回删除后数组的新长度。

不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
*/

/*
示例 1：
输入：nums = [1,1,1,2,2,3]
输出：5, nums = [1,1,2,2,3]
解释：函数应返回新长度 length = 5, 并且原数组的前五个元素被修改为 1, 1, 2, 2, 3。 
不需要考虑数组中超出新长度后面的元素。
*/
#include <vector>
using namespace std;

const int MAX_APPEAR_TIMES = 2;

class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            // 处理空数组
            if (nums.empty()) return 0;

            // 赋值指针
            int assignment_pointer = 0;
            // 记录当前扫描元素和出现次数
            int current_scan_num = nums[0], num_cnt = 0;

            // 扫描指针
            for (int scan_pointer = 0; scan_pointer < nums.size(); scan_pointer++)
            {
                // 处理出现数字
                if(nums[scan_pointer] == current_scan_num)
                    num_cnt++;
                else
                {
                    current_scan_num = nums[scan_pointer];
                    num_cnt = 1;
                }
                if(num_cnt <= MAX_APPEAR_TIMES)
                {
                    nums[assignment_pointer] = nums[scan_pointer];
                    assignment_pointer++;
                }
            }
            return assignment_pointer;
        }
    };

int main()
{
    vector<int> nums = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    Solution S;
    int a = S.removeDuplicates(nums);
    return 0;
}