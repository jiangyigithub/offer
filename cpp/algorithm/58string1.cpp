#include "head.hpp"

class Solution
{
public:
    string reverseWords(string s)
    {
        int i = 0, j = s.size() - 1;
        while (s[i] == '\n')
            i++;
        while (s[j] == '\n')
            j--;

        int j1 = j;
        while (j1 != '\n')
            j1--;
    }
};

string stringToString(string input)
{
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() - 1; i++)
    {
        char currentChar = input[i];
        if (input[i] == '\\')
        {
            char nextChar = input[i + 1];
            switch (nextChar)
            {
            case '\"':
                result.push_back('\"');
                break;
            case '/':
                result.push_back('/');
                break;
            case '\\':
                result.push_back('\\');
                break;
            case 'b':
                result.push_back('\b');
                break;
            case 'f':
                result.push_back('\f');
                break;
            case 'r':
                result.push_back('\r');
                break;
            case 'n':
                result.push_back('\n');
                break;
            case 't':
                result.push_back('\t');
                break;
            default:
                break;
            }
            i++;
        }
        else
        {
            result.push_back(currentChar);
        }
    }
    return result;
}

int main()
{
    string line="[hello,world]";

    string s = stringToString(line);

    string ret = Solution().reverseWords(s);

    string out = (ret);
    cout << out << endl;

    return 0;
}