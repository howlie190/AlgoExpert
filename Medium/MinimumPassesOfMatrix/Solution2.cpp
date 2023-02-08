//
// Created by Justin on 2023/2/8.
//
#include <vector>

using namespace std;

struct Position
{
    Position(int row, int col, int step) : _row(row), _col(col), _step(step) {}
    int _row;
    int _col;
    int _step;
};

void minimumPassesOfMatrixHelper(vector<vector<int>>& matrix,
                                 vector<vector<int>>& steps,
                                 queue<Position>&     myQueue,
                                 Position             pos)
{
    if (pos._row - 1 >= 0 && matrix[pos._row - 1][pos._col] < 0) {
        matrix[pos._row - 1][pos._col] *= -1;
        myQueue.push(Position(pos._row - 1, pos._col, pos._step + 1));
        steps[pos._row - 1][pos._col] = pos._step + 1;
    }
    if (pos._col - 1 >= 0 && matrix[pos._row][pos._col - 1] < 0) {
        matrix[pos._row][pos._col - 1] *= -1;
        myQueue.push(Position(pos._row, pos._col - 1, pos._step + 1));
        steps[pos._row][pos._col - 1] = pos._step + 1;
    }
    if (pos._row + 1 < matrix.size() && matrix[pos._row + 1][pos._col] < 0) {
        matrix[pos._row + 1][pos._col] *= -1;
        myQueue.push(Position(pos._row + 1, pos._col, pos._step + 1));
        steps[pos._row + 1][pos._col] = pos._step + 1;
    }
    if (pos._col + 1 < matrix[pos._row].size() &&
        matrix[pos._row][pos._col + 1] < 0) {
        matrix[pos._row][pos._col + 1] *= -1;
        myQueue.push(Position(pos._row, pos._col + 1, pos._step + 1));
        steps[pos._row][pos._col + 1] = pos._step + 1;
    }
}

int minimumPassesOfMatrix(vector<vector<int>> matrix)
{
    // Write your code here.
    vector<vector<int>> steps(matrix.size(), vector<int>(matrix[0].size(), -1));
    queue<Position>     myQueue;
    int                 step = 0;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] > 0) {
                myQueue.push(Position(i, j, 0));
            }
        }
    }
    while (!myQueue.empty()) {
        Position front = myQueue.front();
        myQueue.pop();
        minimumPassesOfMatrixHelper(matrix, steps, myQueue, front);
    }

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] < 0)
                return -1;
            if (steps[i][j] > step)
                step = steps[i][j];
        }
    }

    return step;
}