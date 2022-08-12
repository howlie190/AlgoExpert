#include <algorithm>
using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
  public:
    int         value;
    BinaryTree* left;
    BinaryTree* right;

    BinaryTree(int value)
    {
        this->value = value;
        left        = nullptr;
        right       = nullptr;
    }
};

struct TreeData
{
    int height;
    int longest;
};

TreeData binaryTreeDiameterHelper(BinaryTree* tree)
{
    if (tree == nullptr)
        return TreeData{0, 0};
    else {
        TreeData leftData  = binaryTreeDiameterHelper(tree->left);
        TreeData rightData = binaryTreeDiameterHelper(tree->right);
        int      height    = max(leftData.height, rightData.height) + 1;
        int      large     = max(leftData.longest, rightData.longest);
        int      longest   = max(leftData.height + rightData.height, large);
        return TreeData{height, longest};
    }
}

int binaryTreeDiameter(BinaryTree* tree)
{
    // Write your code here.
    return binaryTreeDiameterHelper(tree).longest;
}
