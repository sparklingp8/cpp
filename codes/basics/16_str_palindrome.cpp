#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// cpp code to find if string is palindrome
int main()
{
    string str1 = "okopoko";
    string str2 = str1;
    reverse(str1.begin(), str1.end());
    if (!str1.compare(str2)) // return 0 if same
        cout << "It is Palindrome\n";
    else
        cout << "Not Palindrome\n";
}
