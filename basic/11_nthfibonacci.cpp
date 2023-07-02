#include <iostream>
// code to print nth Fibonacci number using recursion in c++
using namespace std;

long fibo(long n)
{

    if (n <= 1)
        return 1;
    else
        return fibo(n - 1) + fibo(n - 2);
}

int main()
{
    long f;
    cout << "Enter which fibbonaci number you want: ";
    cin >> f;
    cout << "\n"
         << f << "th fibonaci number is : " << fibo(f) << endl;
    return 0;
}