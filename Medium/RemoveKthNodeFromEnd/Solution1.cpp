//
// Created by Justin on 2023/3/27.
//
#include <vector>
using namespace std;

class LinkedList {
  public:
    int         value;
    LinkedList* next;

    LinkedList(int value);
    void        addMany(vector<int> values);
    vector<int> getNodesInArray();
};

void removeKthNodeFromEnd(LinkedList* head, int k)
{
    // Write your code here.
    LinkedList* first      = head;
    LinkedList* second     = head;
    int         currentPos = 1;
    while (first->next != nullptr) {
        if (currentPos > k)
            second = second->next;
        currentPos++;
        first = first->next;
    }
    if (currentPos == k) {
        head->value = head->next->value;
        head->next  = head->next->next;
    }
    else {
        second->next = second->next->next;
    }
}