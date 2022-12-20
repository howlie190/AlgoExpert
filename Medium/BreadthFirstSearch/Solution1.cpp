#include <vector>
#include <queue>
using namespace std;

// Do not edit the class below except
// for the breadthFirstSearch method.
// Feel free to add new properties
// and methods to the class.
class Node {
public:
  string name;
  vector<Node *> children;

  Node(string str) { name = str; }

  vector<string> breadthFirstSearch(vector<string> *array) {
    // Write your code here.
    queue<Node*> que;
    Node* current = this;
    que.push(current);
    while(!que.empty())
    {
      current = que.front();
      array->push_back(que.front()->name);
      que.pop();
      for(auto node : current->children)
        que.push(node);
    }
    return *array;
  }

  Node *addChild(string name) {
    Node *child = new Node(name);
    children.push_back(child);
    return this;
  }
};
