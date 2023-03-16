//
// Created by Justin on 2023/3/16.
//
#include <climits>
#include <vector>
using namespace std;

int validStartingCity(vector<int> distances, vector<int> fuel, int mpg)
{
    // Write your code here.
    int range     = 0;
    int remaining = INT_MAX;
    int index     = 0;
    for (int i = 0; i < distances.size(); i++) {
        range += fuel[i] * mpg - distances[i];
        if (range < remaining) {
            remaining = range;
            index     = (i + 1) % distances.size();
        }
    }
    return index;
}
