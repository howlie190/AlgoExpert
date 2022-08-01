using namespace std;

bool isMonotonic(vector<int> array)
{
    bool isIncreasing = true;
    bool isDecreasing = true;
    for (int i = 1; i < array.size(); i++) {
        if (array[i - 1] < array[i])
            isDecreasing = false;
        if (array[i - 1] > array[i])
            isIncreasing = false;
    }
    return isIncreasing || isDecreasing;
}
