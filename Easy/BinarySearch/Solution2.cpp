#include <vector>
using namespace std;

int binarySearch(vector<int> array, int lower, int upper, int target)
{
    if (lower <= upper) {
        int middle = (lower + upper) / 2;
        if (array[middle] == target)
            return middle;
        else if (array[middle] > target)
            return binarySearch(array, lower, middle - 1, target);
        else if (array[middle] < target)
            return binarySearch(array, middle + 1, upper, target);
    }
    return -1;
}

int binarySearch(vector<int> array, int target)
{
    return binarySearch(array, 0, array.size() - 1, target);
}