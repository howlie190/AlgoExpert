//
// Created by Justin on 2023/3/31.
//
#include <queue>
using namespace std;

int staircaseTraversal(int height, int maxSteps) {
    // Write your code here.
    queue<int> myQueue;
    for(int i = 0, step = 0; i <= height; i++) {
        if(i < maxSteps) {
            if(i < 2) {
                myQueue.push(1);
                step++;
            } else {
                myQueue.push(step);
                step *= 2;
            }
        } else {
            myQueue.push(step);
            step = step + (step - myQueue.front());
            myQueue.pop();
        }
    }
    return myQueue.back();
}
