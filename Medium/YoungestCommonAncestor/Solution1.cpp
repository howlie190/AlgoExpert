#include <unordered_map>
#include <vector>
using namespace std;

class AncestralTree {
  public:
    char           name;
    AncestralTree* ancestor;

    AncestralTree(char name)
    {
        this->name     = name;
        this->ancestor = nullptr;
    }

    void addAsAncestor(vector<AncestralTree*> descendants);
};

AncestralTree* getYoungestCommonAncestor(AncestralTree* topAncestor,
                                         AncestralTree* descendantOne,
                                         AncestralTree* descendantTwo)
{
    // Write your code here.
    unordered_map<char, bool> map{};
    while (descendantOne != nullptr || descendantTwo != nullptr) {
        if (descendantOne != nullptr) {
            if (map.find(descendantOne->name) != map.end())
                return descendantOne;
            map.insert({descendantOne->name, true});
            descendantOne = descendantOne->ancestor;
        }
        else if (descendantTwo != nullptr) {
            if (map.find(descendantTwo->name) != map.end())
                return descendantTwo;
            map.insert({descendantTwo->name, true});
            descendantTwo = descendantTwo->ancestor;
        }
    }
    return nullptr;
}
