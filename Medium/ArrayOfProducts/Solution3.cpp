#include <vector>

using namespace std;

vector<int> arrayOfProducts(vector<int> array)
{
    vector<int> products(array.size(), 1);

    int leftRunningProduct = 1;
    for (int i = 0; i < array.size(); i++) {
        products[i] = leftRunningProduct;
        leftRunningProduct *= array[i];
    }

    int rightRunningProduct = 1;
    for (int i = array.size() - 1; i >= 0; i--) {
        products[i] *= rightRunningProduct;
        rightRunningProduct *= array[i];
    }

    return products;
}