#include <unordered_set>
#include <vector>

using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum)
{
    unordered_set<int> hash;
    for (int i : array) {
        int matchNumber = targetSum - i;
        if (hash.find(i) != hash.end())
            return {i, matchNumber};
        else
            hash.insert(matchNumber);
    }
    return {};
}
