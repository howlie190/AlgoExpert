#include <limits>

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

struct TreeInfo
{
    int rootIdx;
}

BST* reconstructBstFromRange(int lowerBound, int upperBound, vector<int> %preOrderTraversalValues, TreeInfo &currentSubtreeInfo)
{
    if (currentSubtreeInfo.rootIdx == preOrderTraversalValues.size())
        return nullptr;

    int rootValue = preOrderTraversalValues[currentSubtreeInfo.rootIdx];

    if (rootValue < lowerBound || rootValue >= upperBound)
        return nullptr;

    currentSubtreeInfo.rootIdx++;

    auto leftSubtree = reconstructBstFromRange(
        lowerBound, rootValue, preOrderTraversalValues, currentSubtreeInfo);
    auto rightSubtree = reconstructBstFromRange(
        rootValue, upperBound, preOrderTraversalValues, currentSubtreeInfo);

    auto bst   = new BST(rootValue);
    bst->left  = leftSubtree;
    bst->right = rightSubtree;
    return bst;
}

BST* reconstructBst(vector<int> preOrderTraversalValues)
{
    auto treeInfo = TreeInfo{0};
    return reconstructBstFromRange(numeric_limits<int>::min(),
                                   numeric_limits<int>::max(),
                                   preOrderTraversalValues, treeInfo);
}