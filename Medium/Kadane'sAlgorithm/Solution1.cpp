#include <algorithm>
#include <climits>
#include <vector>


using namespace std;

int kadanesAlgorithm(vector<int> array)
{
    // Write your code here.
    int result = array[0];
    int temp   = array[0];
    for (int i = 1; i < array.size(); i++) {
        temp   = max(array[i], temp + array[i]);
        result = max(result, temp);
    }
    return result;
}
