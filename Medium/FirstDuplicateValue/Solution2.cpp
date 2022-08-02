#include <algorithm>
#include <vector>

using namespace std;

int firstDuplicateValue(vector<int> array)
{
    for (auto value : array) {
        int absValue = abs(value);
        if (array[absValue - 1] < 0)
            return absValue;
        array[absValue - 1] *= -1;
    }
    return -1;
}