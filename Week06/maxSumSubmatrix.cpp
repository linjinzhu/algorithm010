#include <vector>
#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using std::vector;
using std::string;

int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
    if (matrix.empty()) return 0;
    int row = matrix.size(), col = matrix[0].size(), res = INT_MIN;
    for (int l = 0; l < col; ++l) {
        vector<int> sums(row, 0);
        for (int r = l; r < col; ++r) {
            for (int i = 0; i < row; ++i) {
                sums[i] += matrix[i][r];
            }
            
            // Find the max subarray no more than K 
            set<int> accuSet;
            accuSet.insert(0);
            int curSum = 0, curMax = INT_MIN;
            for (int sum : sums) {
                curSum += sum;
                set<int>::iterator it = accuSet.lower_bound(curSum - k);
                if (it != accuSet.end()) curMax = std::max(curMax, curSum - *it);
                accuSet.insert(curSum);
            }
            res = std::max(res, curMax);
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{

    vector<vector<int>>& matrix;
    vector<int> row;
    for (size_t i = 0; i < 10; i++)
    {
        row.push_back(i);
        matrix.push_back(row);
    }

    maxSumSubmatrix(matrix, 2);

    return 0;
}
