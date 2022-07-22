#include <climits>
#include <vector>

using namespace std;

vector<int> findThreeLargestNumbers(vector<int> array)
{
    int _1st = INT_MIN;
    int _2nd = INT_MIN;
    int _3rd = INT_MIN;
    for (int i = 0; i < array.size(); i++) {
        if (array[i] >= _1st) {
            _3rd = _2nd;
            _2nd = _1st;
            _1st = array[i];
        }
        else if (array[i] >= _2nd && array[i] <= _1st) {
            _3rd = _2nd;
            _2nd = array[i];
        }
        else if (array[i] >= _3rd && array[i] <= _2nd)
            _3rd = array[i];
    }
    return {_3rd, _2nd, _1st};
}
