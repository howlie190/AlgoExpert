#include <vector>

using namespace std;

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
void branchSumsTraversal(BinaryTree* tree, int sum, vector<int>& ans)
{
    if (tree != nullptr) {
        sum += tree->value;
        if (tree->left == nullptr && tree->right == nullptr)
            ans.push_back(sum);
        branchSumsTraversal(tree->left, sum, ans);
        branchSumsTraversal(tree->right, sum, ans);
    }
}
vector<int> branchSums(BinaryTree* root)
{
    vector<int> answer{};
    branchSumsTraversal(root, 0, answer);
    return answer;
}
