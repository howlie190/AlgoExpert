using namespace std;

string caesarCypherEncryptor(string str, int key)
{
    string strMapping = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < str.size(); i++)
        str[i] = strMapping[(strMapping.find(str[i]) + key) % 26];
    return str;
}
