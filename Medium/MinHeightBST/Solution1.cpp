#include <algorithm>

using namespace std;

class BST {
  public:
    int  value;
    BST* left;
    BST* right;

    BST(int value)
    {
        this->value = value;
        left        = nullptr;
        right       = nullptr;
    }

    void insert(int value)
    {
        if (value < this->value) {
            if (left == nullptr) {
                left = new BST(value);
            }
            else {
                left->insert(value);
            }
        }
        else {
            if (right == nullptr) {
                right = new BST(value);
            }
            else {
                right->insert(value);
            }
        }
    }
};

BST* minHeightBstHelper(vector<int> array, int begin, int end)
{
    if (begin <= end) {
        int  mid    = (begin + end) / 2;
        BST* root   = new BST(array[mid]);
        root->left  = minHeightBstHelper(array, begin, mid - 1);
        root->right = minHeightBstHelper(array, mid + 1, end);
        return root;
    }
    return nullptr;
}

BST* minHeightBst(vector<int> array)
{
    // Write your code here.
    return minHeightBstHelper(array, 0, array.size() - 1);
}
