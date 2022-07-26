#include <vector>

using namespace std;

vector<int> bubbleSort(vector<int> array)
{
    for (int i = 0; i < array.size() - 1; i++) {
        bool iFlagSwap = false;
        for (int j = 0; j < array.size() - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
                iFlagSwap = true;
            }
        }
        if (!iFlagSwap)
            break;
    }
    return array;
}
