//
// Created by Justin on 2023/4/10.
//
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> threeNumberSort(vector<int> array, vector<int> order)
{
    // Write your code here.
    unordered_map<int, int> myMap;
    for (auto i : order) {
        myMap[i] = 0;
    }
    for (auto i : array) {
        myMap[i] += 1;
    }
    for (int i = 0, j = 0; i < array.size();) {
        if (myMap[order[j]] == 0) {
            j++;
        }
        else {
            array[i] = order[j];
            myMap[order[j]] -= 1;
            i++;
        }
    }
    return array;
}