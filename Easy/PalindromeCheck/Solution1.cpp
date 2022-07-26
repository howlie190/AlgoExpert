#include <string>

using namespace std;

bool isPalindrome(string str)
{
    int front = 0;
    int rear  = str.length() - 1;
    while (front <= rear) {
        if (str[front] != str[rear])
            return false;
        front++;
        rear--;
    }
    return true;
}
