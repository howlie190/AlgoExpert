#include <unordered_map>

using namespace std;

bool generateDocument(string characters, string document)
{
    unordered_map<char, int> hashTable;
    for (int i = 0; i < characters.size(); i++) {
        if (hashTable.find(characters[i]) == hashTable.end())
            hashTable.emplace(characters[i], 1);
        else
            hashTable[characters[i]]++;
    }
    for (int i = 0; i < document.size(); i++) {
        if (hashTable.find(document[i]) == hashTable.end() ||
            hashTable[document[i]] == 0)
            return false;
        else
            hashTable[document[i]]--;
    }
    return true;
}
