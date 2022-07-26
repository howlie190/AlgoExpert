using namespace std;

bool compare(string str, int index)
{
    int compareIndex = str.size() - 1 - index;
    return index >= compareIndex ?
               true :
               str[index] == str[compareIndex] && compare(str, index + 1);
}

bool isPalindrome(string str)
{
    return compare(str, 0);
}
