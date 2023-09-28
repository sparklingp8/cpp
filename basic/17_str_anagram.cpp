#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// cpp code to find if string is anagram
int main()
{
    string str1 = "koo";
    string str2 = "oko";
    sort(str1.begin(), str1.end());
    sort(str2.begin(),str2.end());
    if (!str1.compare(str2)) // return 0 if same
        cout << "It is Anagram\n";
    else
        cout << "Not Anagram\n";
}
