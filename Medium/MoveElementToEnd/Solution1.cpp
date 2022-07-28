#include <vector>

using namespace std;

vector<int> moveElementToEnd(vector<int> array, int toMove)
{
    int front = 0;
    int rear  = array.size() - 1;
    while (front < rear) {
        if (array[rear] == toMove)
            rear--;
        else if (array[front] == toMove) {
            swap(array[front], array[rear]);
            front++;
            rear--;
        }
        else
            front++;
    }
    return array;
}