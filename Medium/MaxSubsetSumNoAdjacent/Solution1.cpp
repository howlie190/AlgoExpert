#include <algorithm>
#include <vector>

using namespace std;

int maxSubsetSumNoAdjacent(vector<int> array)
{
    // Write your code here.
    if (array.empty())
        return 0;
    vector<int> record(array.size());
    record[0] = array[0];
    record[1] = max(array[0], array[1]);
    for (int i = 2; i < array.size(); i++)
        record[i] = max(record[i - 1], record[i - 2] + array[i]);
    return record[record.size() - 1];
}
