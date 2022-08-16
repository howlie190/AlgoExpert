#include <algorithm>
#include <vector>

using namespace std;

int levenshteinDistance(string str1, string str2)
{
    // Write your code here.
    vector<vector<int>> dynamicProgramming(str1.length() + 1);
    for (int i = 0; i <= str1.length(); i++)
        dynamicProgramming[i].resize(str2.length() + 1, i);
    for (int i = 0; i <= str2.length(); i++)
        dynamicProgramming[0][i] = i;
    for (int i = 1; i <= str1.length(); i++) {
        for (int j = 1; j <= str2.length(); j++) {
            if (str1[i - 1] == str2[j - 1])
                dynamicProgramming[i][j] = dynamicProgramming[i - 1][j - 1];
            else
                dynamicProgramming[i][j] =
                    min(dynamicProgramming[i - 1][j],
                        min(dynamicProgramming[i - 1][j - 1],
                            dynamicProgramming[i][j - 1])) +
                    1;
        }
    }
    return dynamicProgramming[str1.length()][str2.length()];
}
