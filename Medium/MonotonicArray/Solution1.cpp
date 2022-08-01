using namespace std;

bool isMonotonic(vector<int> array)
{
    if (array.empty())
        return true;
    bool flag = array[0] < array.back() ? true : false;
    for (int i = 0; i < array.size() - 1; i++) {
        if (flag) {
            if (array[i] > array[i + 1])
                return false;
        }
        else {
            if (array[i] < array[i + 1])
                return false;
        }
    }
    return true;
}