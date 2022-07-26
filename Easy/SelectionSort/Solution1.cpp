#include <vector>

using namespace std;

vector<int> selectionSort(vector<int> array)
{
    for (int i = 0; i < array.size(); i++) {
        int minIndex = i;
        for (int j = i; j < array.size(); j++) {
            if (array[j] < array[minIndex])
                minIndex = j;
        }
        swap(array[i], array[minIndex]);
    }
    return array;
}
