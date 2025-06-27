#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.push_back({nums[0]});
        for (int i = 1; i < nums.size(); i++)
        {
            vector<vector<int>> tmp;
            for (auto vec : ans)
            {
                vector<int> T;
                for (int j = 0; j <= vec.size(); j++)
                {
                    T.clear();
                    T = vector<int>(vec.begin(), vec.begin() + j);
                    T.push_back(nums[i]);
                    for (int k = j; k < vec.size(); k++)
                        T.push_back(vec[k]);
                    tmp.push_back(T);
                }
            }
            ans = tmp;
        }
        return ans;
    }
};