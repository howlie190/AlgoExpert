//
// Created by Justin on 2023/3/30.
//
// Copyright © 2022 AlgoExpert LLC. All rights reserved.
#include <vector>
#include <numeric>
#include <unordered_map>
using namespace std;
void phoneNumberMnemonicsHelper(int idx, string phoneNumber,
                                                            vector<char> &currentMnemonic,
                                                            vector<string> &mnemonicsFound);
unordered_map<int, vector<char>> DIGIT_LETTERS{
    {0, {'0'}}, {1, {'1'}},
    {2, {'a', 'b', 'c'}}, {3, {'d', 'e', 'f'}},
    {4, {'g', 'h', 'i'}}, {5, {'j', 'k', 'l'}},
    {6, {'m', 'n', 'o'}}, {7, {'p', 'q', 'r', 's'}},
    {8, {'t', 'u', 'v'}}, {9, {'w', 'x', 'y', 'z'}}};
// O(4^n * n) time | O(4^n * n) space - where
// n is the length of the phone number
vector<string> phoneNumberMnemonics(string phoneNumber) {
    vector<char> currentMnemonic(phoneNumber.size(), '0');
    vector<string> mnemonicsFound;
    cout << (int)'4' << endl;
    phoneNumberMnemonicsHelper(0, phoneNumber, currentMnemonic, mnemonicsFound);
    return mnemonicsFound;
}
void phoneNumberMnemonicsHelper(int idx, string phoneNumber,
                                vector<char> &currentMnemonic,
                                vector<string> &mnemonicsFound) {
    if (idx == phoneNumber.size()) {
        string mnemonic =
            accumulate(currentMnemonic.begin(), currentMnemonic.end(), string{});
        mnemonicsFound.push_back(mnemonic);
    } else {
        int digit = phoneNumber[idx] - '0';
        vector<char> letters = DIGIT_LETTERS[digit];
        for (auto letter : letters) {
            currentMnemonic[idx] = letter;
            phoneNumberMnemonicsHelper(idx + 1, phoneNumber, currentMnemonic,
                                       mnemonicsFound);
        }
    }