using namespace std;

int numberOfWaysToTraverseGraph(int width, int height)
{
    // Write your code here.
    vector<vector<int>> dynamicProgramming(height);
    for (int i = 0; i < height; i++)
        dynamicProgramming[i].resize(width, 1);
    for (int i = 1; i < height; i++) {
        for (int j = 1; j < width; j++) {
            dynamicProgramming[i][j] =
                dynamicProgramming[i - 1][j] + dynamicProgramming[i][j - 1];
        }
    }
    return dynamicProgramming[height - 1][width - 1];
}
