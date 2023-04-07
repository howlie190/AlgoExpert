//
// Created by Justin on 2023/4/7.
//
#include <vector>
using namespace std;

vector<int> searchInSortedMatrixHelper(vector<vector<int>>& matrix,
                                       int                  target,
                                       int                  row,
                                       int                  col)
{
    if (row < 0 || row >= matrix.size() || col < 0 ||
        col >= matrix[row].size() || matrix[row][col] == -1) {
        return {-1, -1};
    }
    else if (matrix[row][col] == target) {
        return {row, col};
    }
    else {
        matrix[row][col] = -1;
        vector<int> right =
            searchInSortedMatrixHelper(matrix, target, row + 1, col);
        vector<int> left =
            searchInSortedMatrixHelper(matrix, target, row - 1, col);
        vector<int> down =
            searchInSortedMatrixHelper(matrix, target, row, col + 1);
        vector<int> up =
            searchInSortedMatrixHelper(matrix, target, row, col - 1);
        if (right != vector<int>{-1, -1}) {
            return right;
        }
        else if (left != vector<int>{-1, -1}) {
            return left;
        }
        else if (down != vector<int>{-1, -1}) {
            return down;
        }
        else if (up != vector<int>{-1, -1}) {
            return up;
        }
        else {
            return {-1, -1};
        }
    }
}

vector<int> searchInSortedMatrix(vector<vector<int>> matrix, int target)
{
    // Write your code here.
    return searchInSortedMatrixHelper(matrix, target, 0, 0);
}
