#include <vector>

using namespace std;

vector<int> insertionSort(vector<int> array)
{
    for (int i = 1; i < array.size(); i++) {
        for (int j = i; j > 0; j--) {
            if (array[j] < array[j - 1])
                swap(array[j], array[j - 1]);
        }
    }
    return array;
}
