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
                                 queue<Position>&     myQueue,
                                 Position             pos,
                                 int&                 maxStep)
{
    if (pos._row - 1 >= 0 && matrix[pos._row - 1][pos._col] < 0) {
        matrix[pos._row - 1][pos._col] *= -1;
        myQueue.push(Position(pos._row - 1, pos._col, pos._step + 1));
        maxStep = pos._step + 1 > maxStep ? pos._step + 1 : maxStep;
    }
    if (pos._col - 1 >= 0 && matrix[pos._row][pos._col - 1] < 0) {
        matrix[pos._row][pos._col - 1] *= -1;
        myQueue.push(Position(pos._row, pos._col - 1, pos._step + 1));
        maxStep = pos._step + 1 > maxStep ? pos._step + 1 : maxStep;
    }
    if (pos._row + 1 < matrix.size() && matrix[pos._row + 1][pos._col] < 0) {
        matrix[pos._row + 1][pos._col] *= -1;
        myQueue.push(Position(pos._row + 1, pos._col, pos._step + 1));
        maxStep = pos._step + 1 > maxStep ? pos._step + 1 : maxStep;
    }
    if (pos._col + 1 < matrix[pos._row].size() &&
        matrix[pos._row][pos._col + 1] < 0) {
        matrix[pos._row][pos._col + 1] *= -1;
        myQueue.push(Position(pos._row, pos._col + 1, pos._step + 1));
        maxStep = pos._step + 1 > maxStep ? pos._step + 1 : maxStep;
    }
}

int minimumPassesOfMatrix(vector<vector<int>> matrix)
{
    // Write your code here.
    queue<Position> myQueue;
    int             step = 0;
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
        minimumPassesOfMatrixHelper(matrix, myQueue, front, step);
    }

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] < 0)
                return -1;
        }
    }

    return step;
}