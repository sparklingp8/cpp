#include <iostream>

using namespace std;

// is array sorted using recurssion

int isSortted(int arr[], int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        if (arr[n - 1] < arr[n - 2])
        {
            return 0;
        }
        else
        {
            isSortted(arr, n - 1);
        }
    }
}
int main()
{
    int arr[10];
    int n = 5;

    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter " << i + 1 << " of " << n << " element: ";
        cin >> arr[i];
    }
    if (isSortted(arr, n))
    {
        cout << "\nsorted\n";
    }
    else
    {
        cout << "\nnot sorted\n";
    }
    return 0;
}