//
// Created by Justin on 2023/2/14.
//
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

vector<vector<int>> taskAssignment(int k, vector<int> tasks)
{
    // Write your code here.
    vector<vector<int>>    result;
    vector<pair<int, int>> temp;
    for (int i = 0; i < tasks.size(); i++) {
        temp.push_back(make_pair(i, tasks[i]));
    }
    sort(temp.begin(), temp.end(), [](pair<int, int>& a, pair<int, int>& b) {
        return a.second < b.second;
    });
    for (int i = 0; i < k; i++) {
        result.push_back({temp[i].first, temp[temp.size() - i - 1].first});
    }
    return result;
}
