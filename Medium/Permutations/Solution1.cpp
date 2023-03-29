//
// Created by Justin on 2023/3/29.
//
#include <vector>
#include <utility>

using namespace std;

void getPermutationsHelper(int begin, int end, vector<int> source, vector<vector<int>> &target) {
    if(begin == end) {
        target.push_back(source);
    } else {
        for(int i = begin; i <= end; i++) {
            std::swap(source[begin], source[i]);
            getPermutationsHelper(begin + 1, end, source, target);
        }
    }
}

vector<vector<int>> getPermutations(vector<int> array) {
    // Write your code here.
    vector<vector<int>> ans;
    getPermutationsHelper(0, array.size() - 1, array, ans);
    return ans;
}
