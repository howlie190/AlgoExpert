//
// Created by Justin on 2023/2/9.
//
#include <vector>

using namespace std;

bool twoColorable(vector<vector<int>> edges)
{
    // Write your code here
    vector<int>           stack;
    vector<unsigned char> color(edges.size(), 0);
    color[0] = 1;
    stack.push_back(0);
    while (!stack.empty()) {
        int top = stack.back();
        stack.pop_back();
        for (int i = 0; i < edges[top].size(); i++) {
            if (color[edges[top][i]] != 0) {
                if (color[top] != color[edges[top][i]]) {
                    continue;
                }
                else {
                    return false;
                }
            }
            else {
                color[edges[top][i]] = color[top] == 1 ? 2 : 1;
                stack.push_back(edges[top][i]);
            }
        }
    }
    return true;
}