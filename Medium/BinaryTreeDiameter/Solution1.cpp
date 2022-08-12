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

int binaryTreeHeight(BinaryTree* tree, int sum)
{
    if (tree != nullptr)
        return max(binaryTreeHeight(tree->left, sum + 1),
                   binaryTreeHeight(tree->right, sum + 1));
    return sum;
}

void binaryTreeDiameter(BinaryTree* tree, int& longest)
{
    if (tree != nullptr) {
        int length =
            binaryTreeHeight(tree->left, 0) + binaryTreeHeight(tree->right, 0);
        longest = length > longest ? length : longest;
        binaryTreeDiameter(tree->left, longest);
        binaryTreeDiameter(tree->right, longest);
    }
}

int binaryTreeDiameter(BinaryTree* tree)
{
    // Write your code here.
    int ans = -1;
    binaryTreeDiameter(tree, ans);
    return ans;
}
