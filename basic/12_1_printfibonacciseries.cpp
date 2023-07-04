#include <iostream>
using namespace std;
// print fibonacci series {way 1}
void fibonacci(int i, int a, int b, int limit)
{
    if (i <= limit)
    {

        cout << i << ". " << a << endl;
        i++;
        fibonacci(i, b, a + b, limit);
    }
}

int main()
{
    int limit;
    cout << "Enter the limit: ";
    cin >> limit;

    cout << "Fibonacci series up to " << limit << " :\n";
    fibonacci(1, 0, 1, limit);

    return 0;
}
