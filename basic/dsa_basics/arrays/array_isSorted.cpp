#include <iostream>
using namespace std;

//code to find is array is sorted or not

void isSorted(int ar[], int s)
{

    while (s--)
    {
        if (ar[s] < ar[s - 1])
        {
            cout << "array is NOT sorted";
            return;
        }
    }
    cout << "array is sorted";
}
int main()
{

    int a[] = {1, 2, 3, 4, 7, 9, 11};
    size_t s = sizeof(a) / sizeof(a[0]);
    isSorted(a, s);
    return 0;
}
