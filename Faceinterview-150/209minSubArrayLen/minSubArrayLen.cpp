#include <limits.h>
#include <stdio.h>

#define min(x,y) ((x) < (y) ? (x) : (y))

int minSubArrayLen(int target, int* nums, int numsSize) {
    int left = 0, right = 0;
    int ans = INT_MAX;
    int current = 0;
    while (right < numsSize)
    {
        current += nums[right];
        while (current - nums[left] >= target)
        {
            current -= nums[left];
            left++;
        }
        if (current >= target)
            ans = min(ans, right - left + 1);
        right++;
    }
    return ans == INT_MAX ? 0 : ans;
}

int main()
{
    int nums[] = {1,4,4};
    int size = sizeof(nums);
    printf("%d\n", minSubArrayLen(4, nums, size));
    return 0;
}