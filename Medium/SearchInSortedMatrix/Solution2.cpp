//
// Created by Justin on 2023/4/7.
//
#include <vector>
using namespace std;

vector<int> searchInSortedMatrix(vector<vector<int>> matrix, int target)
{
    // Write your code here.
    int row = 0;
    int col = matrix[row].size() - 1;
    while (row >= 0 && col < matrix[row].size()) {
        if (matrix[row][col] == target) {
            return {row, col};
        }
        else {
            matrix[row][col] > target ? col-- : row++;
        }
    }
    return {-1, -1};
}
