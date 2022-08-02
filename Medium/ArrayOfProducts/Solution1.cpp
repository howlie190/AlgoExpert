#include <vector>

using namespace std;

vector<int> arrayOfProducts(vector<int> array)
{
    vector<int> ans = {};
    for (int i = 0; i < array.size(); i++) {
        int product = 1;
        for (int j = 0; j < array.size(); j++) {
            if (i == j)
                continue;
            product *= array[j];
        }
        ans.push_back(product);
    }
    return ans;
}
