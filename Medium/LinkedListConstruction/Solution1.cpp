//
// Created by Justin on 2023/3/24.
//
using namespace std;

class Node {
  public:
    int   value;
    Node* prev;
    Node* next;

    Node(int value);
};

// Feel free to add new properties and methods to the class.
class DoublyLinkedList {
  public:
    Node* head;
    Node* tail;

    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void setHead(Node* node)
    {
        // Write your code here.
        if (head == nullptr) {
            head = node;
            tail = node;
        }
        else {
            insertBefore(head, node);
        }
    }

    void setTail(Node* node)
    {
        // Write your code here.
        if (tail == nullptr) {
            setHead(node);
        }
        else {
            insertAfter(tail, node);
        }
    }

    void insertBefore(Node* node, Node* nodeToInsert)
    {
        // Write your code here.
        if (nodeToInsert == head && nodeToInsert == tail)
            return;
        remove(nodeToInsert);
        nodeToInsert->prev = node->prev;
        nodeToInsert->next = node;
        if (node->prev == nullptr) {
            head = nodeToInsert;
        }
        else {
            node->prev->next = nodeToInsert;
        }
        node->prev = nodeToInsert;
    }

    void insertAfter(Node* node, Node* nodeToInsert)
    {
        // Write your code here.
        if (nodeToInsert == head && nodeToInsert == tail)
            return;
        remove(nodeToInsert);
        nodeToInsert->prev = node;
        nodeToInsert->next = node->next;
        if (node->next == nullptr) {
            tail = nodeToInsert;
        }
        else {
            node->next->prev = nodeToInsert;
        }
        node->next = nodeToInsert;
    }

    void insertAtPosition(int position, Node* nodeToInsert)
    {
        // Write your code here.
        if (position == 1) {
            setHead(nodeToInsert);
            return;
        }
        Node* current = head;
        int   pos     = 1;
        while (current != nullptr && pos++ != position)
            current = current->next;
        if (current != nullptr) {
            insertBefore(current, nodeToInsert);
        }
        else {
            setTail(nodeToInsert);
        }
    }

    void removeNodesWithValue(int value)
    {
        // Write your code here.
        Node* current = head;
        while (current != nullptr) {
            Node* node = current;
            current    = current->next;
            if (node->value == value)
                remove(node);
        }
    }

    void remove(Node* node)
    {
        // Write your code here.
        if (node == head) {
            head = head->next;
        }
        else if (node == tail) {
            tail = tail->prev;
        }
        if (node->prev != nullptr)
            node->prev->next = node->next;
        if (node->next != nullptr)
            node->next->prev = node->prev;
        node->next = nullptr;
        node->prev = nullptr;
    }

    bool containsNodeWithValue(int value)
    {
        // Write your code here.
        Node* current = head;
        while (current != nullptr && current->value != value)
            current = current->next;
        return current != nullptr;
    }
};