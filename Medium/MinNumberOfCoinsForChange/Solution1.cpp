#include <algorithm>
#include <climits>
#include <vector>


using namespace std;

int minNumberOfCoinsForChange(int n, vector<int> denoms)
{
    // Write your code here.
    vector<int> dynamicProgramming(n + 1, INT_MAX);
    dynamicProgramming[0] = 0;
    for (int i = 0; i < denoms.size(); i++) {
        for (int j = 1; j <= n; j++) {
            if (j >= denoms[i]) {
                int temp = (dynamicProgramming[j - denoms[i]]) == INT_MAX ?
                               INT_MAX :
                               dynamicProgramming[j - denoms[i]] + 1;
                dynamicProgramming[j] = min(temp, dynamicProgramming[j]);
            }
        }
    }
    return dynamicProgramming[n] == INT_MAX ? -1 : dynamicProgramming[n];
}
