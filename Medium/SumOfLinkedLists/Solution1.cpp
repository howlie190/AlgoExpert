//
// Created by Justin on 2023/3/27.
//
using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
  public:
    int         value;
    LinkedList* next = nullptr;

    LinkedList(int value)
    {
        this->value = value;
    }
};

LinkedList* sumOfLinkedLists(LinkedList* linkedListOne,
                             LinkedList* linkedListTwo)
{
    // Write your code here.
    LinkedList* linkedListSum  = nullptr;
    LinkedList* linkedListNode = nullptr;
    int         carry          = 0;
    int         sum            = 0;
    while (linkedListOne != nullptr || linkedListTwo != nullptr || carry) {
        if (linkedListOne != nullptr && linkedListTwo != nullptr) {
            sum   = (linkedListOne->value + linkedListTwo->value + carry) % 10;
            carry = (linkedListOne->value + linkedListTwo->value + carry) / 10;
        }
        else if (linkedListOne != nullptr) {
            sum   = (linkedListOne->value + carry) % 10;
            carry = (linkedListOne->value + carry) / 10;
        }
        else if (linkedListTwo != nullptr) {
            sum   = (linkedListTwo->value + carry) % 10;
            carry = (linkedListTwo->value + carry) / 10;
        }
        else {
            sum   = carry;
            carry = 0;
        }
        if (linkedListSum == nullptr) {
            linkedListSum  = new LinkedList(sum);
            linkedListNode = linkedListSum;
        }
        else {
            linkedListNode->next = new LinkedList(sum);
            linkedListNode       = linkedListNode->next;
        }
        if (linkedListOne != nullptr) {
            linkedListOne = linkedListOne->next;
        }
        if (linkedListTwo != nullptr) {
            linkedListTwo = linkedListTwo->next;
        }
    }
    return linkedListSum;
}