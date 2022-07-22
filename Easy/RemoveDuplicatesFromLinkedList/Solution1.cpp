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

LinkedList* removeDuplicatesFromLinkedList(LinkedList* linkedList)
{
    if (linkedList != nullptr) {
        LinkedList* last    = linkedList;
        LinkedList* current = linkedList->next;
        while (current != nullptr) {
            if (current->value == last->value) {
                last->next = current->next;
                delete current;
                current = last->next;
            }
            else {
                last    = current;
                current = current->next;
            }
        }
        return linkedList;
    }
    return nullptr;
}
