#include <vector>
using namespace std;

int numberOfWaysToMakeChange(int n, vector<int> denoms)
{
    // Write your code here.
    vector<vector<int>> dynamicProgramming(denoms.size() + 1);
    for (int i = 0; i <= denoms.size(); i++) {
        dynamicProgramming[i].resize(n + 1, 0);
        dynamicProgramming[i][0] = 1;
    }
    for (int i = 1; i <= denoms.size(); i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 0; (k * denoms[i - 1]) <= j; k++) {
                dynamicProgramming[i][j] +=
                    dynamicProgramming[i - 1][j - k * denoms[i - 1]];
            }
        }
    }
    return dynamicProgramming[denoms.size()][n];
}
