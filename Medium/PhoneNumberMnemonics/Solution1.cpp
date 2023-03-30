//
// Created by Justin on 2023/3/30.
//
#include <vector>
#include <unordered_map>

using namespace std;

void phoneNumberMnemonicsHelper(string &source, string &subStr, vector<string> &target, unordered_map<int, vector<char>> &map, int idx) {
    if(idx == source.size()) {
        target.push_back(subStr);
        return;
    }
    vector<char> temp = map[std::stoi(string(1, source[idx]))];
    for(int i = 0; i < temp.size(); i++) {
        subStr.push_back(temp[i]);
        phoneNumberMnemonicsHelper(source, subStr, target, map, idx + 1);
        subStr.pop_back();
    }
}

vector<string> phoneNumberMnemonics(string phoneNumber) {
    // Write your code here.
    unordered_map<int, vector<char>> map{{0, {'0'}}, {1, {'1'}}, {2, {'a', 'b', 'c'}},
                                         {3, {'d', 'e', 'f'}}, {4, {'g', 'h', 'i'}}, {5, {'j', 'k', 'l'}},
                                         {6, {'m', 'n', 'o'}}, {7, {'p', 'q', 'r', 's'}}, {8, {'t', 'u', 'v'}},
                                         {9, {'w', 'x', 'y', 'z'}}};
    string subStr;
    vector<string> result;
    phoneNumberMnemonicsHelper(phoneNumber, subStr, result, map, 0);
    return result;
}
