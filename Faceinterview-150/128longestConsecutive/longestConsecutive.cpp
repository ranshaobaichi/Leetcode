#include <vector>
#include <set>
#include <algorithm>  // for std::next

class Solution {
    public:
        int longestConsecutive(std::vector<int>& nums) {
            if (nums.empty()) return 0;
            std::set<int> set(nums.begin(), nums.end());
            int longest = 1, current = 1;
            int pre = *set.begin();
            for (auto it = std::next(set.begin()); it != set.end(); it++)
            {
                if (*it == pre + 1)
                {
                    current++;
                    longest = std::max(longest, current);
                }
                else
                {
                    current = 1;
                }
                pre = *it;
            }
            return longest;
        }
    };