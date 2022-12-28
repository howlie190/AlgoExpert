#include <vector>
using namespace std;

bool cycleInGraphHelper(vector<vector<int>> edges,
                        vector<bool>        visited,
                        int                 vertex)
{
    if (visited[vertex]) {
        return true;
    }
    else {
        bool result     = false;
        visited[vertex] = true;
        for (int i = 0; i < edges[vertex].size(); i++) {
            result =
                result || cycleInGraphHelper(edges, visited, edges[vertex][i]);
        }
        return result;
    }
}

bool cycleInGraph(vector<vector<int>> edges)
{
    // Write your code here.
    for (int i = 0; i < edges.size(); i++) {
        vector<bool> visited(edges.size(), false);
        if (cycleInGraphHelper(edges, visited, i))
            return true;
    }
    return false;
}
