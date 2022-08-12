using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
  public:
    int         value;
    BinaryTree* left   = nullptr;
    BinaryTree* right  = nullptr;
    BinaryTree* parent = nullptr;

    BinaryTree(int value)
    {
        this->value = value;
    }
};

BinaryTree*
findSuccessorHelper(BinaryTree* tree, BinaryTree* node, bool& isFindTarget)
{
    if (tree != nullptr) {
        BinaryTree* left = findSuccessorHelper(tree->left, node, isFindTarget);
        if (left != nullptr)
            return left;
        if (isFindTarget)
            return tree;
        else if (tree == node)
            isFindTarget = true;
        BinaryTree* right =
            findSuccessorHelper(tree->right, node, isFindTarget);
        if (right != nullptr)
            return right;
    }
    return nullptr;
}

BinaryTree* findSuccessor(BinaryTree* tree, BinaryTree* node)
{
    // Write your code here.
    bool isFindTarget = false;
    return findSuccessorHelper(tree, node, isFindTarget);
}
