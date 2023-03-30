//
// Created by Justin on 2023/3/30.
//
#include <vector>
using namespace std;

void powersetHelper(vector<int> &source, vector<int> &subset, vector<vector<int>> &target, int idx) {
    target.push_back(subset);
    for(int i = idx; i < source.size(); i++) {
        subset.push_back(source[i]);
        powersetHelper(source, subset, target, i + 1);
        subset.pop_back();
    }
}

vector<vector<int>> powerset(vector<int> array) {
    // Write your code here.
    vector<vector<int>> result;
    vector<int> subset{};
    powersetHelper(array, subset, result, 0);
    return result;
}
