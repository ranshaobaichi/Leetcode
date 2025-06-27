/*
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。

此外，你可以假设该网格的四条边均被水包围。

 

示例 1：

输入：grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
输出：1
*/
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;
class Solution {
public:
    vector<vector<bool>> vis;
    int ans = 0;
    void bfs(vector<vector<char>>& grid, int i, int j)
    {
        ans++;
        queue<pair<int, int>> dq;
        dq.push({i, j});
        while (!dq.empty())
        {
            auto [posX, posY] = dq.front();
            dq.pop();
            vis[posX][posY] = true;
            if (posX - 1 >= 0 && grid[posX - 1][posY] == '1' && !vis[posX - 1][posY])
                dq.push({posX - 1, posY});
            if (posY - 1 >= 0 && grid[posX][posY - 1] == '1' && !vis[posX][posY - 1])
                dq.push({posX, posY - 1});
            if (posX + 1 < grid.size() && grid[posX + 1][posY] == '1' && !vis[posX + 1][posY])
                dq.push({posX + 1, posY});
            if (posY + 1 < grid[0].size() && grid[posX][posY + 1] == '1' && !vis[posX][posY + 1])
                dq.push({posX, posY + 1});
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        vis.resize(grid.size(), vector<bool>(grid[0].size(), false));
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                if (grid[i][j] == '1' && !vis[i][j])
                    bfs(grid, i, j);
        return ans;
    }
};

int main()
{
    vector<vector<char>> grid = {{'1', '1', '1'}, {'0', '1', '0'}, {'1', '1', '1'}};
    Solution p;
    p.numIslands(grid);
    return 0;
}