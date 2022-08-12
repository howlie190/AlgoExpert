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

BinaryTree* getLeftmostChild(BinaryTree* node)
{
    auto currentNode = node;
    while (currentNode->left != nullptr)
        currentNode = currentNode->left;
    return currentNode;
}

BinaryTree* getRightmostParent(BinaryTree* node)
{
    auto currentNode = node;
    while (currentNode->parent != nullptr &&
           currentNode->parent->right == currentNode)
        currentNode = currentNode->parent;
    return currentNode->parent;
}

BinaryTree* findSuccessor(BinaryTree* tree, BinaryTree* node)
{
    if (node->right != nullptr)
        return getLeftmostChild(node->right);
    return getRightmostParent(node);
}