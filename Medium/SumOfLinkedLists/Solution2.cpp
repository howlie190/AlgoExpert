//
// Created by Justin on 2023/3/27.
//
using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
  public:
    int value;
    LinkedList *next = nullptr;

    LinkedList(int value) { this->value = value; }
};

LinkedList *sumOfLinkedLists(LinkedList *linkedListOne,
                             LinkedList *linkedListTwo) {
    // Write your code here.
    LinkedList* linkedListSum = new LinkedList(0);
    LinkedList* linkedListNode = linkedListSum;
    int carry = 0;
    int sum = 0;
    while(linkedListOne != nullptr || linkedListTwo != nullptr || carry) {
        int one = linkedListOne != nullptr ? linkedListOne->value : 0;
        int two = linkedListTwo != nullptr ? linkedListTwo->value : 0;
        sum = (one + two + carry) % 10;
        carry = (one + two + carry) / 10;
        linkedListNode->next = new LinkedList(sum);
        linkedListNode = linkedListNode->next;
        linkedListOne = linkedListOne != nullptr ? linkedListOne->next : nullptr;
        linkedListTwo = linkedListTwo != nullptr ? linkedListTwo->next : nullptr;
    }
    return linkedListSum->next;
}