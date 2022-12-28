#include <vector>
using namespace std;

int riverSizesHelper(vector<vector<int>>& matrix, int row, int col)
{
    if (row < matrix.size() && row >= 0 && col < matrix[row].size() && col >= 0 &&
        matrix[row][col]) {
        matrix[row][col] = 0;
        return 1 + riverSizesHelper(matrix, row + 1, col) +
               riverSizesHelper(matrix, row - 1, col) +
               riverSizesHelper(matrix, row, col + 1) +
               riverSizesHelper(matrix, row, col - 1);
    }
    return 0;
}

vector<int> riverSizes(vector<vector<int>> matrix)
{
    // Write your code here.
    vector<int> ans;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            int ret = riverSizesHelper(matrix, i, j);
            if (ret)
                ans.push_back(ret);
        }
    }
    return ans;
}
