#include <iostream>
#include <vector>
using namespace std;

// c++ code to print all substring

int main()
{
    string str1 = "hello";
    vector<string> sbstr;
    for (int i = 0; i < str1.length(); i++)
    {
        string temp = "";
        for (int j = i; j < str1.length(); j++)
        {
            temp = temp + str1[j];
            sbstr.push_back(temp);
        }
    }
    for (string s : sbstr)
        cout << s << endl;
}
