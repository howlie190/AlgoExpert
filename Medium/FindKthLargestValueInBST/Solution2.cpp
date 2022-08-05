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

void findKthLargestValueInBst(BST* tree, int k, int* visit, int* ans)
{
    if (tree != nullptr && *visit < k) {
        findKthLargestValueInBst(tree->right, k, visit, ans);
        if (*visit >= k)
            return;
        *ans = tree->value;
        (*visit)++;
        findKthLargestValueInBst(tree->left, k, visit, ans);
    }
}

int findKthLargestValueInBst(BST* tree, int k)
{
    // Write your code here.
    int ans   = -1;
    int visit = 0;
    findKthLargestValueInBst(tree, k, &visit, &ans);
    return ans;
}
