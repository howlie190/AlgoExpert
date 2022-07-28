#include <vector>
using namespace std;

vector<vector<int>> threeNumberSum(vector<int> array, int targetSum)
{
    vector<vector<int>> ans;
    sort(array.begin(), array.end());
    int front;
    int rear;
    for (int i = 0; i < array.size() - 1; i++) {
        front = i + 1;
        rear  = array.size() - 1;
        while (front < rear) {
            if (array[i] + array[front] + array[rear] == targetSum) {
                ans.push_back({array[i], array[front], array[rear]});
                front++;
                rear--;
            }
            else if (array[i] + array[front] + array[rear] < targetSum)
                front++;
            else if (array[i] + array[front] + array[rear] > targetSum)
                rear--;
        }
    }
    return ans;
}
