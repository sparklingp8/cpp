#include <iostream>
#include <vector>
using namespace std;
//cpp code to find char repeat counta
int main()
{
    string str1 = "okkay";
    int count = 0;
    char srch = 'k';
    while (str1.find(srch) != string::npos)
    {
        count++;
        str1.replace(str1.find(srch), 1, "");
    }
    cout << "char " << srch << " repeated: " << count << " times";
}
