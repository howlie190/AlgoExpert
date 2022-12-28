#include <vector>

using namespace std;

bool traverseAndColorNodes(int                  node,
                           vector<vector<int>>& edges,
                           vector<int>&         colors);

enum COLOR { WHITE, GREY, BLACK };

bool cycleInGraph(vector<vector<int>> edges)
{
    int         numberOfNodes = edges.size();
    vector<int> colors(numberOfNodes, COLOR::WHITE);

    for (int node = 0; node < numberOfNodes; node++) {
        if (colors[node] != COLOR::WHITE)
            continue;

        bool containsCycle = traverseAndColorNodes(node, edges, colors);
        if (containsCycle)
            return true;
    }

    return false;
}

bool traverseAndColorNodes(int                  node,
                           vector<vector<int>>& edges,
                           vector<int>&         colors)
{
    colors[node] = COLOR::GREY;

    auto neighbors = edges[node];
    for (auto neighbor : neighbors) {
        int neighborColor = colors[neighbor];

        if (neighborColor == COLOR::GREY)
            return true;
        if (neighborColor == COLOR::BLACK)
            continue;

        bool containCycle = traverseAndColorNodes(neighbor, edges, colors);
        if (containCycle)
            return true;
    }

    colors[node] = COLOR::BLACK;
    return false;
}