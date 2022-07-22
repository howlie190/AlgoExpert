#include <algorithm>
#include <vector>

using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum)
{
    sort(array.begin(), array.end());
    int i = 0;
    int j = array.size() - 1;
    while (i < j) {
        if (array[i] + array[j] != targetSum) {
            if (array[i] + array[j] > targetSum)
                j--;
            else
                i++;
        }
        else
            return {array[i], array[j]};
    }
    return {};
}
