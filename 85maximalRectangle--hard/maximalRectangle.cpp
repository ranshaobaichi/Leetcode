#include<iostream>
#include<vector>
#include<stack>
using namespace std;

/// @brief 方法1：穷举法 依次将每个点视为矩形左上角顶点
/// @brief 优化：空间换时间，找出每行中每个位置为起始右侧最长宽度
class Solution1 {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();

        //构建最长宽度数组
        vector<vector<int>> len(row, vector<int>(col, 0));
        for (int r = 0; r < row; r++)
        {
            int max = 0;
            vector<int>::iterator cur = len[r].end();
            cur--;
            for (int c = col-1; c >=0; c--)
            {
                if (matrix[r][c] == '1')
                    *cur = ++max;
                else
                    max = 0;
                cur--;
            }
        }

        //依次遍历以每个点为左上角的矩形
        //并找出全局最大值
        int ans = 0;
        for (int r = 0; r < row; r++)
            for (int c = 0; c < col; c++)
                if (matrix[r][c] == '1')
                {
                    int height = r, length = INT_MAX;
                    //向下搜索
                    while (height < row && matrix[height][c] != '0')
                    {
                        length = min(length, len[height++][c]);
                        ans = max(ans, (height - r) * length);
                    }
                }
        return ans;
    }
};

class Solution2 {
public:
    int maximalRectangle(vector<vector<char>>& matrix)
    {
        int row = matrix.size(), col = matrix[0].size(), ans = 0;

        //记录以第i行为基底的矩形高度
        vector<vector<int>> len(row, vector<int>(col + 1, 0));
        //初始化最下一行
        for (int c = 0; c < col; c++)
            if (matrix[row - 1][c] == '1')
                len[row - 1][c]++;
        //构建len数组
        for (int c = 0; c < col; c++)
            for (int r = row - 2; r >= 0; r--)
                if (matrix[r][c] == '1')
                    len[r][c] = len[r + 1][c] + 1;

        for (int i = 0; i < row; i++)
            ans = max(ans, singleRectangle(len[i]));

        return ans;
    }
    int singleRectangle(vector<int> height)
    {
        stack<int> S;
        int i = 1, max = -1;
        S.push(-1);
        S.push(0);
        while (i < height.size() + 1)
            if (S.top() == -1 || height[i] > height[S.top()])
                S.push(i++);
            else
            {
                int cur = height[S.top()];
                S.pop();
                max = max > (cur * (i - S.top() - 1)) ? max : (cur * (i - S.top() - 1));
            }
        return max;
    }
};

int main(){
    Solution2 pp;
    // vector<vector<char>> A = { 
    //     { '1', '1', '1', '1', '1', '1', '1', '1' }, 
    //     { '1', '1', '1', '1', '1', '1', '1', '0' }, 
    //     { '1', '1', '1', '1', '1', '1', '1', '0' }, 
    //     { '1', '1', '1', '1', '1', '0', '0', '0' }, 
    //     { '0', '1', '1', '1', '1', '0', '0', '0' } 
    // };
    vector<vector<char>> A = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '1'}
    };
    cout<<pp.maximalRectangle(A);
    return 0;
}