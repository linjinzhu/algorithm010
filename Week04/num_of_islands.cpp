#include <vector>
#include <queue>
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

class SolutionDFS {

private:
void dfs(vector<vector<char> >& grid, int row, int col) {
    int nr = grid.size();
    int nc = grid[0].size();

    grid[row][col] = '0';
    if (row - 1 >= 0 && grid[row - 1][col] == '1') {
        dfs(grid, row - 1, col);
    }
    if (row + 1 < nr && grid[row + 1][col] == '1') {
        dfs(grid, row + 1, col);
    }
    if (col - 1 >= 0 && grid[row][col - 1] == '1') {
        dfs(grid, row, col - 1);
    }
    if (col + 1 < nc && grid[row][col + 1] == '1') {
        dfs(grid, row, col + 1);
    }
}

public:
int numIslands(vector<vector<char> >& grid) {
    int ans = 0;

    int nr = grid.size();
    int nc = grid[0].size();
    for (size_t row = 0; row < nr; row++) {
        for (size_t col = 0; col < nc; col++) {
            if (grid[row][col] == '1') {
                dfs(grid, row, col);
                ans++;
            }
        }
    }

    return ans;
}
};

class SolutionBFS {
public:
int numIslands(vector<vector<char> >& grid) {
    int ans = 0;

    int nr = grid.size();
    int nc = grid[0].size();

    for (size_t row = 0; row < nr; row++) {
        for (size_t col = 0; col < nc; col++) {
            if (grid[row][col] == '0') {
                continue;
            }

            std::queue<std::pair<int, int> > neighbors;
            neighbors.push(std::make_pair<int, int>(row, col));

            while (!neighbors.empty()) {
                std::pair<int, int> rc = neighbors.front();
                neighbors.pop();
                int row = rc.first;
                int col = rc.second;

                if (row - 1 >= 0 && grid[row - 1][col] == '1') {
                    grid[row - 1][col] = '0';
                    neighbors.push(std::make_pair<int, int>(row - 1, col));
                }
                if (row + 1 < nr && grid[row + 1][col] == '1') {
                    grid[row + 1][col] = '0';
                    neighbors.push(std::make_pair<int, int>(row + 1, col));
                }
                if (col - 1 >= 0 && grid[row][col - 1] == '1') {
                    grid[row][col - 1] = '0';
                    neighbors.push(std::make_pair<int, int>(row, col - 1));
                }
                if (col + 1 < nc && grid[row][col + 1] == '1') {
                    grid[row][col + 1] = '0';
                    neighbors.push(std::make_pair<int, int>(row, col + 1));
                }
            }
            
            ans++;
        }
    }

    return ans;
}


};

int main(int argc, char const *argv[]) {
    SolutionBFS s;
    vector<vector<char> > grid;
    for (size_t i = 0; i < 3; i++)
    {
        vector<char> row;
        for (size_t j = 0; j < 3; j++)
        {
            row.push_back('1');
        }
        grid.push_back(row);
    }

    std::cout << "num:" << s.numIslands(grid) << std::endl;
    return 0;
}
