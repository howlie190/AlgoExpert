#include <vector>
using namespace std;

// Do not edit the class below except for
// the insert, contains, and remove methods.
// Feel free to add new properties and methods
// to the class.
class BST {
  public:
    int  value;
    BST* left;
    BST* right;

    BST(int val)
    {
        value = val;
        left  = nullptr;
        right = nullptr;
    }

    BST& insert(int val)
    {
        // Write your code here.
        // Do not edit the return statement of this method.
        if (val < value) {
            if (left == nullptr)
                left = new BST(val);
            else
                left->insert(val);
        }
        else if (val >= value) {
            if (right == nullptr)
                right = new BST(val);
            else
                right->insert(val);
        }
        return *this;
    }

    bool contains(int val)
    {
        // Write your code here.
        BST* current = this;
        while (current != nullptr) {
            if (current->value == val)
                return true;
            else if (current->value > val)
                current = current->left;
            else if (current->value < val)
                current = current->right;
        }
        return false;
    }

    int getMin()
    {
        if (this->left == nullptr)
            return this->value;
        else
            return this->left->getMin();
    }

    int getMax()
    {
        if (this->right == nullptr)
            return this->value;
        else
            return this->right->getMax();
    }

    void getTarget(BST** parent, BST** target, int val)
    {
        BST* current = this;
        while (current != nullptr) {
            if (current->value == val) {
                *target = current;
                current = nullptr;
            }
            else if (current->value > val) {
                *parent = current;
                current = current->left;
            }
            else if (current->value < val) {
                *parent = current;
                current = current->right;
            }
        }
    }

    BST* removeHelper(int val, BST* parent = nullptr)
    {
        BST* target = nullptr;
        getTarget(&parent, &target, val);
        if (target == nullptr)
            return this;
        if (target->left == nullptr && target->right == nullptr) {
            parent->left == target ? parent->left  = nullptr :
                                     parent->right = nullptr;
            delete target;
        }
        else if (target->left != nullptr && target->right == nullptr) {
            if (parent == nullptr) {
                value = left->getMax();
                left->removeHelper(value, this);
            }
            else {
                parent->left == target ? parent->left  = target->left :
                                         parent->right = target->left;
                delete target;
            }
        }
        else if (target->right != nullptr && target->left == nullptr) {
            if (parent == nullptr) {
                value = right->getMin();
                right->removeHelper(value, this);
            }
            else {
                parent->left == target ? parent->left  = target->right :
                                         parent->right = target->right;
                delete target;
            }
        }
        else {
            target->value = target->right->getMin();
            target->right->removeHelper(target->value, target);
        }
        return this;
    }

    BST& remove(int val)
    {
        // Write your code here.
        // Do not edit the return statement of this method.
        if (left == nullptr && right == nullptr)
            return *this;
        return *removeHelper(val);
    }
};
