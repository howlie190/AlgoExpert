#include <vector>
using namespace std;

void removeIslandsHelper(vector<vector<int>>& nonerasable,
                         vector<vector<int>>& matrix,
                         int                  row,
                         int                  col)
{
    if (row < matrix.size() && row >= 0 && col < matrix[0].size() && col >= 0 &&
        !nonerasable[row][col] && matrix[row][col]) {
        nonerasable[row][col] = 1;
        removeIslandsHelper(nonerasable, matrix, row + 1, col);
        removeIslandsHelper(nonerasable, matrix, row - 1, col);
        removeIslandsHelper(nonerasable, matrix, row, col + 1);
        removeIslandsHelper(nonerasable, matrix, row, col - 1);
    }
}

vector<vector<int>> removeIslands(vector<vector<int>> matrix)
{
    // Write your code here.
    vector<vector<int>> nonerasable(matrix.size(),
                                    vector<int>(matrix[0].size(), 0));
    for (int i = 0; i < matrix[0].size(); i++) {
        if (!nonerasable[0][i])
            removeIslandsHelper(nonerasable, matrix, 0, i);
    }
    for (int i = 0; i < matrix.size(); i++) {
        if (!nonerasable[i][0])
            removeIslandsHelper(nonerasable, matrix, i, 0);
    }
    for (int i = 0; i < matrix[0].size(); i++) {
        if (!nonerasable[matrix.size() - 1][i])
            removeIslandsHelper(nonerasable, matrix, matrix.size() - 1, i);
    }
    for (int i = 0; i < matrix.size(); i++) {
        if (!nonerasable[i][matrix[0].size() - 1])
            removeIslandsHelper(nonerasable, matrix, i, matrix[0].size() - 1);
    }
    return nonerasable;
}
