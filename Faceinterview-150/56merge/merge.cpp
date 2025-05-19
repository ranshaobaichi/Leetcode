#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
            sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) -> bool
                 { return a[0] < b[0]; });
            vector<vector<int>> ans;
            if (intervals.empty()) return ans;
            
            auto cur = intervals.begin();
            vector<int> current = *cur;
            cur++;
            
            while (cur != intervals.end())
            {
                if ((*cur)[0] <= current[1]) {
                    current[1] = max(current[1], (*cur)[1]);
                } else {
                    ans.push_back(current);
                    current = *cur;
                }
                cur++;
            }
            
            ans.push_back(current);
            return ans;
        }
    };