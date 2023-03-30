//
// Created by Justin on 2023/3/30.
//
#include <vector>
#include <cmath>

using namespace std;


vector<vector<int>> powerset(vector<int> array) {
    // Write your code here.
    vector<vector<int>> result;
    for(int i = 0; i < pow(2, array.size()); i++) {
        vector<int> temp;
        for(int j = 1; j < pow(2, array.size()); j <<= 1) {
            int afterMask = i & j;
            if(afterMask)
                temp.push_back(array[log2(afterMask)]);
        }
        result.push_back(temp);
    }
    return result;
}
