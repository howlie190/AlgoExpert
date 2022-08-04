#include <climits>

class BST {
  public:
    int  value;
    BST* left;
    BST* right;

    BST(int val);
    BST& insert(int val);
};

bool validateBst(BST* tree, int maxValue, int minValue)
{
    if (tree->value < minValue || tree->value >= maxValue)
        return false;
    else if (tree->left != nullptr &&
             !validateBst(tree->left, tree->value, minValue))
        return false;
    else if (tree->right != nullptr &&
             !validateBst(tree->right, maxValue, tree->value))
        return false;
    return true;
}

bool validateBst(BST* tree)
{
    // Write your code here.
    return validateBst(tree, INT_MAX, INT_MIN);
}
