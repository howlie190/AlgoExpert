#include <vector>

using namespace std;

void findOnesConnectedToBorder(vector<vector<int>>& matrix, int stratRow, int startCol, vector<vector<bool>>& onesConnectedToBorder);

vector<vector<int>> getNeighbors(vector<vector<int>>& matrix, int row, int col);

vector<vector<int>> removeIslands(vector<vector<int>> matrix) {
    vector<vector<bool>> onesConnectedToBorder;
    for(int i = 0; i < matrix.size(); i++) {
        onesConnectedToBorder.push_back(vector<bool>(matrix[0].size(), false));
    }

    for(int row = 0; row < matrix.size(); row++) {
        for(int col = 0; col < matrix[row].size(); col++) {
            bool rowIsBorder = row == 0 || row == matrix.size() - 1;
            bool colIsBorder = col == 0 || col == matrix[row].size() - 1;
            bool isBorder = rowIsBorder || colIsBorder;

            if(!isBorder)
                continue;
            if(matrix[row][col] != 1)
                continue;

            findOnesConnectedToBorder(matrix, row, col, onesConnectedToBorder);
        }
    }

    for(int row = 1; row < matrix.size() - 1; row++) {
        for(int col = 1; col < matrix[row].size() - 1; col++) {
            if(onesConnectedToBorder[row][col])
                continue;
            matrix[row][col] = 0;
        }
    }

    return matrix;
}

void findOnesConnectedToBorder(vector<vector<int>>& matrix, int stratRow, int startCol, vector<vector<bool>>& onesConnectedToBorder) {
    vector<vector<int>> stack = {{startRow, startCol}};

    while(stack.size() > 0) {
        auto currentPosition = stack[stack.size() - 1];
        stack.pop_back();
        int currentRow = currentPosition[0];
        int currentCol = currentPosition[1];

        bool alreadyVisited = onesConnectedToBorder[currentRow][currentCol];
        if(alreadyVisited)
            continue;
        
        onesConnectedToBorder[currentRow][currentCol] = true;

        auto neighbors = getNeighbors(matrix, currentRow, currentCol);
        for(auto neighbor : neighbors) {
            int row = neighbor[0];
            int col = neighbor[1];

            if(matrix[row][col] != 1)
                continue;
            stack.push_back(neighbor);
        }
    }
}

vector<vector<int>> getNeighbors(vector<vector<int>>& matrix, int row, int col) {
    vector<vector<int>> neighbors;
    int numRows = matrix.size();
    int numCols = matrix[row].size();

    if(row - 1 > 0)
        neighbors.push_back(vector<int>{row - 1, col});
    if(row + 1 > 0)
        neighbors.push_back(vector<int>{row + 1, col});
    if(col - 1 > 0)
        neighbors.push_back(vector<int>{row, col - 1});
    if(col + 1 > 0)
        neighbors.push_back(vector<int>{row, col + 1});
    return neighbors;
}