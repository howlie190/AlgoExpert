#include <iostream>

using namespace std;

class BinaryTree
{
public:
    int value;
    BinaryTree *left;
    BinaryTree *right;

    BinaryTree(int value)
    {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};
int DepthSum(BinaryTree *tree, int sum)
{
    if (tree != NULL)
        return DepthSum(tree->left, sum + 1) + DepthSum(tree->right, sum + 1) + sum;
    return 0;
}
int nodeDepths(BinaryTree *root)
{
    return DepthSum(root, 0);
}
