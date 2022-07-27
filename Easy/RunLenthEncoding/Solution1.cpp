using namespace std;

string runLengthEncoding(string str)
{
    if (str.size() == 0)
        return "";
    char   ch    = str[0];
    int    count = 1;
    string ans;
    for (int i = 1; i < str.size(); i++) {
        if (ch != str[i] || count > 8) {
            ans += to_string(count);
            ans += ch;
            ch    = str[i];
            count = 1;
        }
        else
            count++;
    }
    ans += to_string(count);
    ans += ch;
    return ans;
}
