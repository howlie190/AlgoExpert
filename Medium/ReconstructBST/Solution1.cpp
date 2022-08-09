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

BST* reconstructBstHelper(vector<int> array, int begin, int end)
{
    if (begin > end) {
        return nullptr;
    }
    else {
        int index = begin + 1;
        while (index <= end) {
            if (array[index] >= array[begin])
                break;
            index++;
        }
        BST* node   = new BST(array[begin]);
        node->left  = reconstructBstHelper(array, begin + 1, index - 1);
        node->right = reconstructBstHelper(array, index, end);
        return node;
    }
}

BST* reconstructBst(vector<int> preOrderTraversalValues)
{
    // Write your code here.
    return reconstructBstHelper(preOrderTraversalValues, 0,
                                preOrderTraversalValues.size() - 1);
}
