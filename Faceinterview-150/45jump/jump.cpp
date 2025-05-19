#include <stdio.h>
int jump(int* nums, int numsSize) {
    if (numsSize <= 1)
        return 0;
    int last_far = 0, current_far = nums[0];
    int steps = 1;
    while (current_far < numsSize - 1)
    {
        int end = current_far, start = last_far;
        last_far = current_far + 1;
        for (int i = start; i <= end; i++)
            if (i + nums[i] > current_far)
                current_far = i + nums[i];
        steps++;
    }
    return steps;
}

int main()
{
    int a[] = {2, 3, 0, 1, 4};
    printf("%d\n", jump(a, 5));
    return 0;
}