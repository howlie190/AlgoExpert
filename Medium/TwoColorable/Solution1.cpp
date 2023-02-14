//
// Created by Justin on 2023/2/9.
//
#include <queue>

using namespace std;

struct Node
{
    bool          _marked = false;
    unsigned char _color;
    unsigned char _index;
};

bool twoColorable(vector<vector<int>> edges)
{
    // Write your code here.
    vector<Node> records(edges.size());
    for (int i = 0; i < records.size(); i++)
        records[i]._index = i;
    queue<Node> myQueue;
    records[0]._color  = 0;
    records[0]._marked = true;
    for (int i = 0; i < edges[0].size(); i++) {
        records[edges[0][i]]._color  = 1;
        records[edges[0][i]]._marked = true;
        myQueue.push(records[edges[0][i]]);
    }
    while (!myQueue.empty()) {
        for (int i = 0; i < edges[myQueue.front()._index].size(); i++) {
            if (records[edges[myQueue.front()._index][i]]._marked) {
                if (myQueue.front()._color !=
                    records[edges[myQueue.front()._index][i]]._color) {
                    continue;
                }
                else {
                    return false;
                }
            }
            else {
                records[edges[myQueue.front()._index][i]]._marked = true;
                records[edges[myQueue.front()._index][i]]._color =
                    myQueue.front()._color == 1 ? 0 : 1;
                myQueue.push(records[edges[myQueue.front()._index][i]]);
            }
        }
        myQueue.pop();
    }
    return true;
}
