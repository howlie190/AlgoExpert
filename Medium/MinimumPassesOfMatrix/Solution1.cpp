//
// Created by Justin on 2023/2/8.
//
#include <vector>

using namespace std;

bool minimumPassesOfMatrixHelper(vector<vector<int>>  matrix,
                                 vector<vector<bool>> checked,
                                 int                  row,
                                 int                  col)
{
    if (row + 1 < matrix.size() && matrix[row + 1][col] > 0 &&
        !checked[row + 1][col]) {
        return true;
    }
    else if (row - 1 >= 0 && matrix[row - 1][col] > 0 &&
             !checked[row - 1][col]) {
        return true;
    }
    else if (col + 1 < matrix[row].size() && matrix[row][col + 1] > 0 &&
             !checked[row][col + 1]) {
        return true;
    }
    else if (col - 1 >= 0 && matrix[row][col - 1] > 0 &&
             !checked[row][col - 1]) {
        return true;
    }
    else {
        return false;
    }
}

int minimumPassesOfMatrix(vector<vector<int>> matrix)
{
    // Write your code here.
    int                       ret = 0;
    bool                      converted;
    bool                      check;
    std::vector<vector<bool>> checked(
        matrix.size(), std::vector<bool>(matrix[0].size(), false));
    do {
        converted = false;
        check     = false;
        for (auto& i : checked) {
            std::fill(i.begin(), i.end(), false);
        }
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] < 0) {
                    if (minimumPassesOfMatrixHelper(matrix, checked, i, j)) {
                        checked[i][j] = true;
                        matrix[i][j] *= -1;
                        converted = true;
                    }
                    else {
                        check = true;
                    }
                }
            }
        }
        if (converted)
            ret++;
    } while (converted);
    return check ? -1 : ret;
}