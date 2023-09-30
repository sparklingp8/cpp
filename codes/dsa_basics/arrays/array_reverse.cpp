#include <iostream>

using namespace std;

// code to reverse array, with the method of swapping two elements at a time
void rever(int arr[], int s)
{
    int t;
    int front = 0;
    int end = s - 1;
    while (front < end)
    {
        t = arr[end];
        arr[end] = arr[front];
        arr[front] = t;
        front++;
        end--;
    }
}
void printArr(int *arrPtr, int siz)
{
    int i = 0;
    while (i != siz)
    {
        cout << *arrPtr++ << ", ";
        i++;
    }
    cout << "\n";
}

int main()
{
    
    int arr[] = {1,2};
    int siz = sizeof(arr) / sizeof(int);
    cout << "Before reverse: ";
    printArr(arr, siz);
    rever(arr, siz);
    cout << "After reverse: ";
    printArr(arr, siz);

    return 0;
}