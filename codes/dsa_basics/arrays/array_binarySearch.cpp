#include <iostream>
using namespace std;

// c++ code to do binar search on Sorted array
int binarySearch(int arr[], int n, int target)
{
    int left = 0;
    int right = n - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2; //Important
        if (arr[mid] == target)
        {
            return mid; // Found at index mid
        }
        else if (arr[mid] < target)
        {

            left = mid + 1;
        }
        else
        {

            right = mid - 1;
        }
    }
    return -1; // Not found
}

int main()
{
    int ar[] = {2, 3, 5, 56, 677, 5646, 6373};
    int s = sizeof(ar) / sizeof(ar[0]);

    int k = 677;
    int findKey = binarySearch(ar, s, k);
    if (findKey != -1)
    {
        cout << k << " Found at index: " << findKey << endl;
    }
    else
    {
        cout << k << " is Not present in given array" << endl;
        ;
    }
    return 0;
}