#include <unordered_map>

using namespace std;

int firstNonRepeatingCharacter(string string)
{
    unordered_map<char, int> hashTable;
    for (int i = 0; i < string.size(); i++) {
        if (hashTable.find(string[i]) == hashTable.end())
            hashTable[string[i]] = 1;
        else
            hashTable[string[i]]++;
    }
    for (int i = 0; i < string.size(); i++) {
        if (hashTable.at(string[i]) == 1)
            return i;
    }
    return -1;
}
