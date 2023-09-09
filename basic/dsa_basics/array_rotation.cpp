#include <iostream>
using namespace std;

// code to rotate array right or left 'n' number of times one rotation at a time

void leftrot(int arr[], int sz)
{
    int i, t = arr[0];
    for (i = 0; i < sz - 1; i++)
        arr[i] = arr[i + 1];
    arr[sz - 1] = t;
}

void rightrot(int arr[], int sz)
{
    int i = 0;
    int t = arr[sz - 1];
    for (i = sz - 1; i > 0; i--)
        arr[i] = arr[i - 1];
    arr[0] = t;
}

void printArr(int *arrPtr, int siz)
{
    int i = 0;
    while (i < siz - 1)
    {
        cout << *arrPtr++ << ", ";
        i++;
    }
    cout << *arrPtr;
    cout << "\n";
}

int main()
{

    int rotate, chc;
    int arr[] = {1, 2, 3, 4, 5};
    int siz = sizeof(arr) / sizeof(arr[0]);

    cout << "Choose:\n1.To rotate RIGHT\n2.To rotate LEFT\nEnter your choice: ";
    cin >> chc;
    cout << "Enter the times to be rotated: ";
    cin >> rotate;

    cout << "Before  rotation: ";
    printArr(arr, siz);

    rotate = rotate % siz;

    while (rotate--)
    {
        if (chc == 1)
            rightrot(arr, siz);
        else
            leftrot(arr, siz);
    }
    cout << "After  rotation: ";
    printArr(arr, siz);

    return 0;
}
