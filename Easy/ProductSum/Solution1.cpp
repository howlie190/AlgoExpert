#include <any>
#include <typeinfo>
#include <vector>

using namespace std;

// Tip: You can use el.type() == typeid(vector<any>) to check whether an item is
// a list or an integer.
// If you know an element of the array is vector<any> you can cast it using:
//     any_cast<vector<any>>(element)
// If you know an element of the array is an int you can cast it using:
//     any_cast<int>(element)
int productSum(vector<any> array, int multiplier = 1)
{
    int ans = 0;
    for (int i = 0; i < array.size(); i++) {
        if (array[i].type() == typeid(int))
            ans += any_cast<int>(array[i]);
        else
            ans += productSum(any_cast<vector<any>>(array[i]), multiplier + 1);
    }
    return multiplier * ans;
}
