#include <vector>
using namespace std;

class Solution {
    public:
        void rotate(vector<vector<int>>& matrix) {
            size_t size = matrix.size();
            // 转置
            for (size_t i = 0; i < size; i++)
                for (size_t j = i + 1; j < size; j++)
                    swap(matrix[i][j], matrix[j][i]);
            // 旋转180度
            for (size_t i = 0; i < size; i++)
                for (size_t j = 0; j < size / 2; j++)
                    swap(matrix[i][j], matrix[i][size - j - 1]);
        }
    };