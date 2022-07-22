#include <unordered_map>
#include <vector>

using namespace std;

string tournamentWinner(vector<vector<string>> competitions,
                        vector<int>            results)
{
    unordered_map<string, int> imap;
    pair<string, int>          highest("", 0);
    for (int i = 0; i < competitions.size(); i++) {
        if (imap.find(competitions[i][!results[i]]) == imap.end())
            imap.insert(pair<string, int>(competitions[i][!results[i]], 3));
        else
            imap[competitions[i][!results[i]]] += 3;
        if (imap[competitions[i][!results[i]]] > highest.second) {
            highest.first  = competitions[i][!results[i]];
            highest.second = imap[competitions[i][!results[i]]];
        }
    }
    return highest.first;
}
