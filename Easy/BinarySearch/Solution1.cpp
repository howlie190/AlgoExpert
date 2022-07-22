#include <vector>
using namespace std;

int binarySearch(vector<int> array, int target)
{
    int lower = 0;
    int upper = array.size() - 1;
    while (lower <= upper) {
        int middle = (upper + lower) / 2;
        if (array[middle] == target)
            return middle;
        else if (array[middle] > target)
            upper = middle - 1;
        else if (array[middle] < target)
            lower = middle + 1;
    }
    return -1;
}
