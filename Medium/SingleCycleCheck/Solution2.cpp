using namespace std;

bool hasSingleCycle(vector<int> array) {
    // Write your code here.
    int visitedCount = 0;
    int index = 0;
    while(visitedCount < array.size())
    {
        if(visitedCount && !index)
            return false;
        visitedCount++;
        index = (index + array[index]) % (int)array.size();
        if(index < 0)
            index += array.size();
    }
    return index == 0;
}
