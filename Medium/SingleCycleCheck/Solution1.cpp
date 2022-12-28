using namespace std;

using namespace std;

bool hasSingleCycle(vector<int> array)
{
    // Write your code here.
    vector<bool> table(array.size(), false);
    int          count = array.size();
    int          index = 0;
    while (1) {
        if (!index && !count)
            return true;
        else if (table[index])
            return false;
        else {
            table[index] = true;
            index        = (index + array[index]) % (int)array.size();
            if (index < 0)
                index += (int)array.size();
            count--;
        }
    }
}