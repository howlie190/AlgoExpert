//
// Created by Justin on 2023/2/14.
//
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<int, vector<int>> getTaskDurationsToIndices(vector<int> tasks);

vector<vector<int>> taskAssignment(int k, vector<int> tasks)
{
    vector<vector<int>> pairedTasks;
    auto taskDurationToIndices = getTaskDurationsToIndices(tasks);

    vector<int> sortedTasks(tasks);
    sort(sortedTasks.begin(), sortedTasks.end());

    for (int idx = 0; idx < k; idx++) {
        auto task1Duration           = sortedTasks[idx];
        auto indicesWitTask1Duration = &taskDurationToIndices[task1Duration];
        auto task1Index              = indicesWitTask1Duration->back();
        indicesWitTask1Duration->pop_back();

        auto task2SortedIndex         = tasks.size() - 1 - idx;
        auto task2Duration            = sortedTasks[task2SortedIndex];
        auto indicesWithTask2Duration = &taskDurationToIndices[task2Duration];
        auto task2Index               = indicesWithTask2Duration->back();
        indicesWithTask2Duration->pop_back();

        pairedTasks.push_back(vector<int>{task1Index, task2Index});
    }
    return pairedTasks;
}

unordered_map<int, vector<int>> getTaskDurationsToIndices(vector<int> tasks)
{
    unordered_map<int, vector<int>> taskDurationToIndices;

    for (int idx = 0; idx < tasks.size(); idx++) {
        auto taskDuration = tasks[idx];
        if (taskDurationToIndices.find(taskDuration) !=
            taskDurationToIndices.end()) {
            taskDurationToIndices[taskDuration].push_back(idx);
        }
        else {
            taskDurationToIndices[taskDuration] = vector<int>{idx};
        }
    }
    return taskDurationToIndices;
}
