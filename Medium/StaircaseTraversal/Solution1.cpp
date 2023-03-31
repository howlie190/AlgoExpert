//
// Created by Justin on 2023/3/31.
//
using namespace std;

void staircaseTraversalHelper(int height, int maxSteps, int currentHeight, int& ways) {
    if(currentHeight == height) {
        ways++;
        return;
    }
    for(int i = 1; i <= maxSteps; i++) {
        if(currentHeight + i <= height)
            staircaseTraversalHelper(height, maxSteps, currentHeight + i, ways);
    }
}

int staircaseTraversal(int height, int maxSteps) {
    // Write your code here.
    int result = 0;
    staircaseTraversalHelper(height, maxSteps, 0, result);
    return result;
}
