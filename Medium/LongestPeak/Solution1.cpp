#include <vector>

using namespace std;

int longestPeak(vector<int> array)
{
    if (array.size() < 3)
        return 0;
    int  ans        = 0;
    int  current    = 0;
    bool increasing = false;
    bool decreasing = false;
    for (int i = 0; i < array.size() - 1; i++) {
        if (current == 0) {
            if (array[i] < array[i + 1]) {
                current    = 2;
                increasing = true;
            }
        }
        else {
            if (increasing) {
                if (array[i] > array[i + 1]) {
                    current++;
                    ans        = ans < current ? current : ans;
                    increasing = false;
                    decreasing = true;
                }
                else if (array[i] < array[i + 1])
                    current++;
                else {
                    current    = 0;
                    increasing = false;
                }
            }
            else if (decreasing) {
                if (array[i] > array[i + 1]) {
                    current++;
                    ans = ans < current ? current : ans;
                }
                else {
                    current = 0;
                    i--;
                    decreasing = false;
                }
            }
        }
    }
    return ans;
}
