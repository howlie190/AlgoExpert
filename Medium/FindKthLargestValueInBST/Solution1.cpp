using namespace std;

// This is an input class. Do not edit.
class BST {
  public:
    int  value;
    BST* left  = nullptr;
    BST* right = nullptr;

    BST(int value)
    {
        this->value = value;
    }
};

void findKthLargestValueInBstHelper(BST* tree, vector<int>& array)
{
    if (tree != nullptr) {
        findKthLargestValueInBstHelper(tree->left, array);
        array.push_back(tree->value);
        findKthLargestValueInBstHelper(tree->right, array);
    }
}

int findKthLargestValueInBst(BST* tree, int k)
{
    // Write your code here.
    vector<int> result = {};
    findKthLargestValueInBstHelper(tree, result);
    return result[result.size() - k];
}
