#include <unordered_map>
#include <vector>

using namespace std;

int firstDuplicateValue(vector<int> array)
{
    unordered_map<int, bool> hashTable;
    for (int i = 0; i < array.size(); i++) {
        if (hashTable.find(array[i]) != hashTable.end())
            return array[i];
        else
            hashTable.insert({array[i], true});
    }
    return -1;
}
