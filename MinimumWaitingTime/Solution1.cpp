#include <algorithm>
using namespace std;

int minimumWaitingTime(vector<int> queries)
{
    int ans = 0;
    int sum = 0;
    sort(queries.begin(), queries.end());
    for (int i = 0; i < queries.size() - 1; i++)
    {
        sum += queries[i];
        ans += sum;
    }
    return ans;
}
