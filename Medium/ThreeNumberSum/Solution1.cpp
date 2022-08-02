#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeNumberSum(vector<int> array, int targetSum)
{
    vector<vector<int>> ans;
    sort(array.begin(), array.end());
    for (int i = 0; i < array.size(); i++)
        for (int j = i + 1; j < array.size(); j++)
            for (int k = j + 1; k < array.size(); k++)
                if (array[i] + array[j] + array[k] == targetSum)
                    ans.push_back({array[i], array[j], array[k]});
    return ans;
}
