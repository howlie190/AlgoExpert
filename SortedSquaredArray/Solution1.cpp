#include <vector>
#include <algorithm>
using namespace std;

vector<int> sortedSquaredArray(vector<int> array)
{
    int rear = array.size() - 1;
    int front = 0;
    vector<int> ans(array.size());
    for (int i = array.size() - 1; i >= 0; i--)
    {
        if (abs(array[front]) >= abs(array[rear]))
            ans[i] = pow(array[front++], 2);
        else
            ans[i] = pow(array[rear--], 2);
    }
    return ans;
}
