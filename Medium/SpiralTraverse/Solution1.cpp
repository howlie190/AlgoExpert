#include <vector>

using namespace std;

enum class Direction { RIGHT, DOWN, LEFT, UP };

void spiralTraverseHelper(vector<vector<int>> array,
                          int                 startRow,
                          int                 startCol,
                          int                 endRow,
                          int                 endCol,
                          vector<int>&        result)
{
    int       currentRow = startRow;
    int       currentCol = startCol;
    Direction direction  = Direction::RIGHT;
    if (startRow > endRow || startCol > endCol)
        return;
    do {
        result.push_back(array[currentRow][currentCol]);
        switch (direction) {
            case Direction::RIGHT:
                if (currentCol + 1 > endCol) {
                    currentRow++;
                    direction = Direction::DOWN;
                }
                else
                    currentCol++;
                break;
            case Direction::DOWN:
                if (currentRow + 1 > endRow) {
                    currentCol--;
                    direction = Direction::LEFT;
                }
                else
                    currentRow++;
                break;
            case Direction::LEFT:
                if (currentCol - 1 < startCol) {
                    currentRow--;
                    direction = Direction::UP;
                }
                else
                    currentCol--;
                break;
            case Direction::UP: currentRow--; break;
        }
    } while ((currentRow >= startRow && currentRow <= endRow &&
              currentCol >= startCol && currentCol <= endCol) &&
             !(currentRow == startRow && currentCol == startCol));
    spiralTraverseHelper(array, startRow + 1, startCol + 1, endRow - 1,
                         endCol - 1, result);
}

vector<int> spiralTraverse(vector<vector<int>> array)
{
    if (array.empty())
        return {};
    vector<int> ans;
    spiralTraverseHelper(array, 0, 0, array.size() - 1, array[0].size() - 1,
                         ans);
    return ans;
}
