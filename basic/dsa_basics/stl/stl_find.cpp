#include <iostream>
#include <algorithm>
//c++ code to find a number using STL find()
using namespace std;

int main()
{
    int arr[] = {1, 2, 8, 3, 4, 5, 6, };
    size_t n = sizeof(arr) / sizeof(arr[0]);

    auto it = find(arr, arr + n, 4); //takes address
   
    if (it != arr + n)
    {
        cout << "found at index: " << distance(arr, it);
    }
    else
    {
        cout << "not found";
    }
    return 0;
}
