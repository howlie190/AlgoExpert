//
// Created by Justin on 2023/3/30.
//
#include <vector>
using namespace std;

vector<vector<int>> powerset(vector<int> array) {
    // Write your code here.
    vector<vector<int>> result{{}};
    for(auto value : array) {
        int len = result.size();
        for(int i = 0; i < len; i++) {
            vector<int> temp = result[i];
            temp.push_back(value);
            result.push_back(temp);
        }
    }
    return result;
}
