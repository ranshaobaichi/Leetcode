#include <vector>
#include <deque>
using namespace std;

class Solution {
    private:
        enum Direction
        {
            RIGHT = 0,
            DOWN,
            LEFT,
            UP
        };

    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            vector<int> result;
            deque<deque<int>> M;
            for (const auto& row : matrix) {
                M.push_back(deque<int>(row.begin(), row.end()));
            }
            Direction direction = RIGHT;
            while (!M.empty() && !M.front().empty())
            {
                switch (direction)
                {
                    case RIGHT:
                        for (auto it = M.front().begin(); it != M.front().end(); ++it)
                            result.push_back(*it);
                        M.pop_front();
                        break;
                    case LEFT:
                        for (auto it = M.back().rbegin(); it != M.back().rend(); ++it)
                            result.push_back(*it);
                        M.pop_back();
                        break;
                    case UP:
                        for (auto it = M.rbegin(); it != M.rend(); ++it)
                        {
                            result.push_back((*it).front());
                            (*it).pop_front();
                        }
                        break;
                    case DOWN:
                        for (auto it = M.begin(); it != M.end(); ++it)
                        {
                            result.push_back((*it).back());
                            (*it).pop_back();
                        }
                        break;
                }
                direction = static_cast<Direction>((static_cast<int>(direction) + 1) % 4);
            }
            return result;
        }
    };