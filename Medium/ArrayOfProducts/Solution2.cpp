#include <vector>

using namespace std;

vector<int> arrayOfProducts(vector<int> array)
{
    vector<int> leftToRight(array.size());
    vector<int> rightToLeft(array.size());
    vector<int> ans(array.size());
    for (int i = 0, product = 1; i < array.size(); i++) {
        product *= array[i];
        leftToRight[i] = product;
    }
    for (int i = array.size() - 1, product = 1; i >= 0; i--) {
        product *= array[i];
        rightToLeft[i] = product;
    }
    for (int i = 0; i < array.size(); i++) {
        if (i == 0)
            ans[i] = rightToLeft[i + 1];
        else if (i == array.size() - 1)
            ans[i] = leftToRight[i - 1];
        else
            ans[i] = leftToRight[i - 1] * rightToLeft[i + 1];
    }
    return ans;
}
