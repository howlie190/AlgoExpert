#include <cmath>
class BST
{
public:
    int value;
    BST *left;
    BST *right;

    BST(int val);
    BST &insert(int val);
};
void findClosest(BST *tree, int target, int &closest)
{
    if (tree != NULL)
    {
        if (abs(target - tree->value) < abs(target - closest))
            closest = tree->value;
        findClosest(tree->left, target, closest);
        findClosest(tree->right, target, closest);
    }
}
int findClosestValueInBst(BST *tree, int target)
{
    int closestValue = tree->value;
    findClosest(tree, target, closestValue);
    return closestValue;
}
