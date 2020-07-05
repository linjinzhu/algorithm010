#include <vector>
#include <iostream>
using std::vector;
class Solution {
private:
    void dfs(vector<vector<char> >& grid, int r, int c) {
        int nr = grid.size();
        int nc = grid[0].size();

        grid[r][c] = '0';
        if (r - 1 >= 0 && grid[r-1][c] == '1') dfs(grid, r - 1, c);
        if (r + 1 < nr && grid[r+1][c] == '1') dfs(grid, r + 1, c);
        if (c - 1 >= 0 && grid[r][c-1] == '1') dfs(grid, r, c - 1);
        if (c + 1 < nc && grid[r][c+1] == '1') dfs(grid, r, c + 1);
    }

public:
    int numIslands(vector<vector<char> >& grid) {
        int nr = grid.size();
        if (!nr) return 0;
        int nc = grid[0].size();

        int num_islands = 0;
        for (int r = 0; r < nr; ++r) {
            for (int c = 0; c < nc; ++c) {
                if (grid[r][c] == '1') {
                    ++num_islands;
                    dfs(grid, r, c);
                }
            }
        }

        return num_islands;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    vector<vector<char> > grid;
    for (size_t i = 0; i < 3; i++)
    {
        vector<char> row;
        for (size_t j = 0; j < 3; j++)
        {
            row.push_back('0');
        }
        grid.push_back(row);
    }

    std::cout << "num:" << s.numIslands(grid) << std::endl;
    return 0;
}
