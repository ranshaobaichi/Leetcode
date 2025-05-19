#include <vector>
using namespace std;
class Solution {
public:
    const int start = 0;
    const int end = 1;
    vector<vector<int>> insert(vector<vector<int>>&& intervals, vector<int>&& newInterval) {
        vector<vector<int>> ret;
        int index = 0;
        while (index < intervals.size() && intervals[index][start] < newInterval[start])
        {
            ret.push_back(intervals[index]);
            index++;
        }

        bool need_insert_left = false, need_insert_right = false;
        if (index > 0 && intervals[index - 1][end] >= newInterval[start])
            need_insert_left = true;
        if (index < intervals.size() && intervals[index][start] <= newInterval[end])
            need_insert_right = true;

        if (need_insert_left && need_insert_right)
        {
            ret.pop_back();
            ret.push_back(vector<int>{intervals[index - 1][start], intervals[index][end]});
        }
        else if (need_insert_left)
        {
            ret.pop_back();
            ret.push_back(vector<int>{intervals[index - 1][start], newInterval[end]});
            if (index < intervals.size())
                ret.push_back(intervals[index]);
        }
        else if (need_insert_right)
        {
            ret.push_back(vector<int>{newInterval[start], intervals[index][end]});
        }
        else
        {
            ret.push_back(newInterval);
            if (index < intervals.size())
                ret.push_back(intervals[index]);
        }

        for (int i = index + 1; i < intervals.size(); i++)
            ret.push_back(intervals[i]);

        return ret;
    }
};

int main()
{
    Solution p;
    p.insert(vector<vector<int>>{{1, 3}, {6, 9}}, vector<int>{2, 5});
    return 0;
}