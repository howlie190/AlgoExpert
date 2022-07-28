#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo)
{
    sort(arrayOne.begin(), arrayOne.end());
    sort(arrayTwo.begin(), arrayTwo.end());
    int iter1 = 0, iter2 = 0, index1 = 0, index2 = 0;
    int diff = INT_MAX;
    while (iter1 < arrayOne.size() && iter2 < arrayTwo.size()) {
        if (arrayOne[iter1] - arrayTwo[iter2] == 0)
            return {arrayOne[iter1], arrayTwo[iter2]};
        if (abs(arrayOne[iter1] - arrayTwo[iter2]) < diff) {
            diff   = abs(arrayOne[iter1] - arrayTwo[iter2]);
            index1 = iter1;
            index2 = iter2;
        }
        arrayOne[iter1] < arrayTwo[iter2] ? iter1++ : iter2++;
    }
    return {arrayOne[index1], arrayTwo[index2]};
}
