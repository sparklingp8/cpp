#include <iostream>
//factorial function using recursion 
using namespace std;

int factorial(long n)
{
    if (n == 0)
        return 1;
    else
        return n * (factorial(n - 1));
}

int main()
{
    long i;
    cout << "\nEnter number to be factorised: ";
    cin >> i;
    cout << "\nFactorial of " << i << " is: " << factorial(i) << endl;
    return 0;
}
