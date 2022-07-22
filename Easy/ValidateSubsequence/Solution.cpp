#include <vector>
using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence)
{
    vector<int>::iterator it = sequence.begin();
    for (auto i : array) {
        if (i == *it)
            it++;
        if (it == sequence.end())
            return true;
    }
    return false;
}
