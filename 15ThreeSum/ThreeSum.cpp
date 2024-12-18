#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    void quickSort(std::vector<int>& arr) {
        if (arr.empty()) return;
        quickSort(arr, 0, arr.size() - 1);
    }

    void quickSort(std::vector<int>& arr, int left, int right) {
        if (left >= right) return; // 递归退出条件应为 left >= right
        if (left + 1 == right)
        {
            if (arr[left] > arr[right])
                std::swap(arr[left], arr[right]);
            return;
        }

        // 左、中、右选取中值作为枢纽元
        int mid = (left + right) / 2;
        if (arr[left] > arr[mid]) std::swap(arr[left], arr[mid]);
        if (arr[left] > arr[right]) std::swap(arr[left], arr[right]);
        if (arr[mid] > arr[right]) std::swap(arr[mid], arr[right]);

        // 中值放到倒数第二个位置，最大值留在末尾
        std::swap(arr[mid], arr[right - 1]);
        int pivot = arr[right - 1];

        // 分区操作
        int i = left, j = right - 1;
        while (true) {
            while (arr[++i] < pivot);
            while (pivot < arr[--j]);

            if (i < j) {
                std::swap(arr[i], arr[j]);
            } else {
                break;
            }
        }

        // 将枢纽元放到正确位置
        std::swap(arr[i], arr[right - 1]);

        // 递归对左右区间排序
        quickSort(arr, left, i - 1);
        quickSort(arr, i + 1, right);
    }
 
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3)
            return vector<vector<int>>();
        quickSort(nums);
        vector<vector<int>> ans;
        int sz = nums.size();
        int left = 0;
        while (left + 1 < sz)
        {
            int mid = left + 1, right = sz - 1;
            int target = -nums[left];
            while (mid < right)
            {
                while (right > mid && nums[mid] + nums[right] > target)
                    right--;
                if(right == mid) break;
                if(nums[mid] + nums[right] == target)
                    ans.push_back({nums[left], nums[mid], nums[right]});
                mid++;
                while (mid < sz - 1 && (nums[mid] == nums[mid - 1] || nums[mid] + nums[right] < target))
                    mid++;
            }
            left++;
            while (left + 1 < sz && nums[left] == nums[left - 1])
                left++;
        }
        return ans;
    }
};

int main(){
    vector<int> in = {-1, 0, 1, 2, -1, -4};
    Solution pp;
    vector<vector<int>> ans = pp.threeSum(in);
    for (vector<int> a : ans)
    {
        for (int b : a)
            cout << b << ' ';
        cout << endl;
    }
    return 0;
}