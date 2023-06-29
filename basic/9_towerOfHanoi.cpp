#include <iostream>
// For n disks, total 2^n – 1 moves are required.
using namespace std;

void towerOfHanoi(int n, char a, char c, char b)
{
    if (n == 1)
    {
        cout << "Move disk " << n << " " << a << " to " << c << endl;
        return;
    }
    towerOfHanoi(n - 1, a, b, c);
    cout << "Move disk " << n << " " << a << " to " << c << endl;
    towerOfHanoi(n - 1, b, c, a);
}

int main()
{

    int disks;
    char a = 'a', b = 'b', c = 'c';
    cout << "\nEnter number of disks: ";
    cin >> disks;
    towerOfHanoi(disks, a, c, b);
    return 0;
}