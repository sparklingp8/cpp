#include <iostream>

using namespace std;
// code to print till nth Fibonacci number using recursion in c++ 
int fib(int n)
{
    if (n <= 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fib(n - 1) + fib(n - 2);
}
int main()
{
    int f = 10;
    for (int i = 0; i < f; i++)
        cout << fib(i) << ", ";
    return 0;
}
