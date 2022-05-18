#include <iostream>
#include <string>

using namespace std;
int findsubstr(const char* str, char* sub)
{
    int result = 0;
    int nCount;
    while (*str != '\0')
    {
        result++;
        nCount = 0;
        while (*str == *sub && *sub != '\0')
        {
            str++;
            sub++;
            nCount++;
        }
        if (*sub == '\0') break;
        sub = sub - nCount;
        str = str - nCount;
        str++;
        if (*str == '\0')
            result = -1;
    }
    return result;
}

int main()
{
    string strInput;
    string strFind;
    cout << "Input string: ";
    getline(cin, strInput);
    do {
        cout << "Input string find: ";
        getline(cin, strFind);
    } while (strFind.length() > strInput.length());

    int i_strSize = strInput.length() + 1;
    char* str = new char[i_strSize];
    str[i_strSize - 1] = '\0';
    for (int i = 0; i < i_strSize; i++)
    {
        str[i] = strInput[i];
    }

    int i_subSize = strFind.length() + 1;
    char* sub = new char[i_subSize];
    sub[i_subSize - 1] = '\0';
    for (int i = 0; i < i_subSize; i++)
    {
        sub[i] = strFind[i];
    }
    cout << "Result: " << findsubstr(str, sub);
    delete[] str;
    delete[] sub;
    return 0;
}