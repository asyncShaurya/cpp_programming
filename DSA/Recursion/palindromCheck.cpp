#include <iostream>
using namespace std;

bool checkPalindrom(string str, int i, int j)
{
    // base case
    if (i > j)
    {
        return true;
    }
    if (str[i] != str[j])
    {
        return false;
    }
    else
    {
        // Recursive call
        return checkPalindrom(str, i + 1, j - 1);
    }
}
int main()
{
    string name = "abbabba";
    bool isPalindrom = checkPalindrom(name, 0, name.length() - 1);

    if (isPalindrom)
    {
        cout << "Its a palindrome " << endl;
    }
    else
    {
        cout << " It's not a palindrome" << endl;
    }

    return 0;
}