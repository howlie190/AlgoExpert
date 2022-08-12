#include <algorithm>

using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
  public:
    int         value;
    BinaryTree* left  = nullptr;
    BinaryTree* right = nullptr;

    BinaryTree(int value)
    {
        this->value = value;
    }
};

struct TreeData
{
    int  height;
    bool isBalanced;
};

TreeData heightBalancedBinaryTreeHelper(BinaryTree* tree)
{
    if (tree == nullptr)
        return TreeData{0, true};
    else {
        TreeData left       = heightBalancedBinaryTreeHelper(tree->left);
        TreeData right      = heightBalancedBinaryTreeHelper(tree->right);
        bool     isBalanced = false;
        if (left.isBalanced && right.isBalanced)
            isBalanced = (abs(left.height - right.height) > 1) ? false : true;
        int height = max(left.height, right.height) + 1;
        return TreeData{height, isBalanced};
    }
}

bool heightBalancedBinaryTree(BinaryTree* tree)
{
    // Write your code here.
    return heightBalancedBinaryTreeHelper(tree).isBalanced;
}
