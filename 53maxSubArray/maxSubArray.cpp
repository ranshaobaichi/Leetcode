#include <vector>
#include <algorithm>
class Solution {
    public:
        int findMax(std::vector<int>& nums, int left, int right)
        {
            if (left + 1 >= right)
                return nums[left];
            int mid = (left + right) / 2;
            int cross_max = INT_MIN, left_max = 0, right_max = 0;
            int left_current = 0, right_current = 0;
            for (int i = mid - 1; i >= left; i--)
            {
                left_current += nums[i];
                if (left_current > left_max)
                    left_max = left_current;
            }
            for (int i = mid + 1; i < right; i++)
            {
                right_current += nums[i];
                if (right_current > right_max)
                    right_max = right_current;                
            }
            cross_max = nums[mid] + left_max + right_max;
            return std::max(cross_max, std::max(findMax(nums, left, mid), findMax(nums, mid, right)));
        }
        int maxSubArray(std::vector<int>& nums) {
            return findMax(nums, 0, nums.size());
        }
};

int main()
{
    std::vector<int> a = {-2, 1};
    Solution p;
    p.maxSubArray(a);
    return 0;
}