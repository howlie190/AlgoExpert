//
// Created by Justin on 2023/3/28.
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

LinkedList* mergingLinkedLists(LinkedList* linkedListOne,
                               LinkedList* linkedListTwo)
{
    // Write your code here.
    LinkedList* first  = linkedListOne;
    LinkedList* second = linkedListTwo;
    while (first != second) {
        if (first == nullptr) {
            first = linkedListTwo;
        }
        else {
            first = first->next;
        }
        if (second == nullptr) {
            second = linkedListOne;
        }
        else {
            second = second->next;
        }
    }
    return first;
}
