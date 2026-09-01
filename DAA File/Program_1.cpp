#include <iostream>
using namespace std;
int linear(int arr[], int n, int k, int i)
{
    if (i >= n)
        return -1;
    if (arr[i] == k)
        return i;
    return linear(arr, n, k, i + 1);
}
int binary(int arr[], int low, int high, int k)
{
    if (low > high)
        return -1;
    int mid = low + (high - low) / 2;
    if (arr[mid] == k)
        return mid;
    if (k < arr[mid])
        return binary(arr, low, mid - 1, k);
    return binary(arr, mid + 1, high, k);
}
int main()
{
    int n, k, choice;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements in sorted order: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "\nEnter element to search: ";
    cin >> k;
    cout << "\n1. Linear Search";
    cout << "\n2. Binary Search";
    cout << "\nEnter your choice: ";
    cin >> choice;
    int result;
    if (choice == 1)
        result = linear(arr, n, k, 0);
    else if (choice == 2)
        result = binary(arr, 0, n - 1, k);
    else
    {
        cout << "Invalid choice";
        return 0;
    }
    if (result != -1)
        cout << "\nElement found at: " << result + 1 << endl;
    else
        cout << "\nElement not found." << endl;
    return 0;
}
