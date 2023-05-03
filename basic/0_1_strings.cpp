#include <iostream>
using namespace std;
//strings code
int main()
{
    char c[5];
    cin.get(c, 5);
    for (int i = 0; (int)c[i] != 0; i++)
    {
        cout << "|" << (int)c[i] << "-" << c[i] << "|" << endl;
    }
    return 0;
}
