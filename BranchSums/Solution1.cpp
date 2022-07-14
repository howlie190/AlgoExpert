#include <vector>

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
void branchSumsTraversal(BinaryTree *tree, int sum, vector<int> &ans)
{
    if (tree != NULL)
    {
        sum += tree->value;
        if (tree->left == NULL && tree->right == NULL)
            ans.push_back(sum);
        branchSumsTraversal(tree->left, sum, ans);
        branchSumsTraversal(tree->right, sum, ans);
    }
}
vector<int> branchSums(BinaryTree *root)
{
    vector<int> answer{};
    branchSumsTraversal(root, 0, answer);
    return answer;
}
