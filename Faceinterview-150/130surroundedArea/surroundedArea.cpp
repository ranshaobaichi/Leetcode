#include <iostream>
#include <vector>
using namespace std;

class Solution {
    private:
        vector<vector<bool>> visited;
    public:
        bool dfs(vector<vector<char>>& board, int x, int y)
        {
            if (x < 0 || y < 0 || x >= board.size() || y >= board.size())
                return true;   // don't need to change the character
            if (visited[x][y] || board[x][y] == 'X')
                return false;
            visited[x][y] = true;
            bool change = dfs(board, x - 1, y) || dfs(board, x + 1, y) || dfs(board, x, y - 1) || dfs(board, x, y + 1);
            if (!change)
                board[x][y] = 'X';
            return change;
        }
        void solve(vector<vector<char>>& board) {
            visited.resize(board.size(), vector<bool>(board[0].size(), false));
            for (int i = 0; i < board.size(); i++)
                for (int j = 0; j < board.size(); j++)    
                    if (board[i][j] == 'O')
                        dfs(board, i, j);
        }
    };

int main()
{
    vector<vector<char>> vec = {{'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'}};
    Solution p;
    p.solve(vec);
    return 0;
}