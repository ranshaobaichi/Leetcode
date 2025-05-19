/*
给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。
你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
返回 滑动窗口中的最大值 。

示例 1：
输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
输出：[3,3,5,5,6,7]
解释：
滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

示例 2：
输入：nums = [1], k = 1
输出：[1]
 
提示：
1 <= nums.length <= 105
-104 <= nums[i] <= 104
1 <= k <= nums.length
*/
#include <vector>
#include <queue>
#include <assert.h>
using namespace std;

class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            struct Node{
                int val;
                int index;
                Node(int v, int i) : val(v), index(i) { }
            };
            struct cmp
            {
                bool operator()(Node a, Node b) { return a.val < b.val; }
            };
            
            priority_queue<Node,vector<Node>,cmp> maxHeap;
            vector<int> ans;
            // init the heap
            for (int i = 0; i < k; i++)
                maxHeap.push(Node(nums[i], i));
            // record the left and right of the window
            int left = 0, right = k - 1;
            while (true)
            {
                // push the ans
                ans.push_back(maxHeap.top().val);
                if (right + 1 >= nums.size())
                    break;
                // pop the left element
                while (!maxHeap.empty() && maxHeap.top().index <= left)
                    maxHeap.pop();

                // push the right element
                if (nums[right + 1] > maxHeap.top().val)
                    while (!maxHeap.empty())
                        maxHeap.pop();
                maxHeap.push(Node(nums[right + 1], right + 1));

                left++;
                right++;
            }
            return ans;
        }
    };

/*
the O(k) Solution
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> q;
        for (int i = 0; i < k; ++i) {
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
        }

        vector<int> ans = {nums[q.front()]};
        for (int i = k; i < n; ++i) {
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
            while (q.front() <= i - k) {
                q.pop_front();
            }
            ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};

作者：力扣官方题解
链接：https://leetcode.cn/problems/sliding-window-maximum/solutions/543426/hua-dong-chuang-kou-zui-da-zhi-by-leetco-ki6m/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

int main(){
    Solution S;
    // vector<int> test = {1, 3, -1, -3, 5, 3, 6, 7}, ans = {3, 3, 5, 5, 6, 7};
    // assert(S.maxSlidingWindow(test, 3) == ans);
    vector<int> test = {-1, 1}, ans = {-1, 1};
    assert(S.maxSlidingWindow(test, 1) == ans);
    return 0;
}