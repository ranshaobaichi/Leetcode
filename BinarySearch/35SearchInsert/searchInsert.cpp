#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
//查找数组中值为target的元素；若不存在则返回应插入位置
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = (left + right) >> 1;
            if (target <= nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left;
    }
};

int main(){
    vector<int> A = {1, 3, 5, 6};

    Solution pp;
    cout << pp.searchInsert(A, 2);

    return 0;
}