#include <iostream>
using namespace std;
// print fibonacci till the last number is below given limit
void fibonacci(int a, int b, int limit)
{
    if (a <= limit)
    {
        cout << a << " ";
        fibonacci(b, a + b, limit);
    }
}

int main()
{
    int limit;
    cout << "Enter the limit: ";
    cin >> limit;

    cout << "Fibonacci series up to " << limit << " : ";
    fibonacci(0, 1, limit);

    return 0;
}
