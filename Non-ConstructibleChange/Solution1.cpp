#include <vector>
#include <algorithm>
using namespace std;

int nonConstructibleChange(vector<int> coins)
{
    sort(coins.begin(), coins.end());
    int result = 0;
    for (auto i : coins)
    {
        if (i <= result + 1)
            result += i;
        else
            return result + 1;
    }
    return result + 1;
}
